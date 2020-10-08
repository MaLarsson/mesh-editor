"""Convert IFC types and entities to C++ types"""

"""Globals"""
_IfcVersion = "IFC4X1"
_IfcSchemaFile = _IfcVersion + ".exp"
_CppTypeFile = "type.h"
_CppEntityFile = "entity.h"
_Type = "TYPE "
_Entity = "ENTITY "
_End = "END_"
_Types = ["BOOLEAN", "NUMBER", "REAL", "INTEGER", "STRING", "BINARY"]
_Containers = ["ARRAY", "LIST", "SET", "ENUMERATION", "SELECT", "LOGICAL"]
_TypeMap = {
    "BOOLEAN": "bool",
    "NUMBER": "double",
    "REAL": "double",
    "INTEGER": "int",
    "STRING": "std::string",
    "BINARY": "std::vector<std::byte>",
    "ARRAY": "std::array",
    "LIST": "std::vector",
    "SET": "std::unordered_set",
    "SELECT": "std::variant"
}

"""Converter factory"""
class ConverterFactory:
    def get_converter(self, block):
        converter = None
        if block.startswith(_Type):
            converter = self.get_type_converter(block)
        elif block.startswith(_Entity):
            converter = EntityConverter()
        return converter

    def get_type_converter(self, block):
        type = container = converter = None
        block = block.replace(";", "")
        tokens = block.split()
        name = tokens[1]
        for t in tokens[3:]:
            if name == "IfcSizeSelect": print(tokens)
            if t in _Types or t.startswith("Ifc"):
                type = t
            elif t in _Containers:
                container = t
            elif t.startswith("STRING"):
                type = "STRING"

        if container in ["ENUMERATION", "SELECT", "LOGICAL"]:
            converter = DomainTypeConverter()
        elif container in _Containers:
            converter = ContainerTypeConverter(name, type, container)
        elif type is not None:
            converter = BasicTypeConverter(name, type)
        return converter


"""Abstract converter"""
class AbsConverter:
    output = None
    def convert(self):
        pass

"""Abstract type converter"""
class AbsTypeConverter(AbsConverter):
    pass

"""Basic type converter"""
class BasicTypeConverter(AbsTypeConverter):
    name = ""
    type = ""
    prefix = "using"

    def __init__(self, name, type):
        self.name = name
        self.type = type

    def get_cpp_type(self, type):
        t = None
        try:
            t = _TypeMap[type]
        except KeyError:
            if type.startswith("Ifc"):
                t = type
        return t

    def convert(self):
        t = self.get_cpp_type(self.type)
        if t is None:
            print("Failed to get type for: " + self.type)
        else:
            self.output = self.prefix + " " + self.name + " = " + t + ";"

"""Container type converter"""
class ContainerTypeConverter(BasicTypeConverter):
    container = ""

    def __init__(self, name, type, container):
        super().__init__(name, type)
        self.container = container

    def convert(self):
        c = self.get_cpp_type(self.container)
        t = self.get_cpp_type(self.type)

        if t is None or c is None:
            print("Failed to get type for: ", self.container, self.type)
        else:
            self.output = self.prefix + " " + self.name + " = " + c + "<" + t + ">;"


"""Domain type converter"""
class DomainTypeConverter(AbsTypeConverter):
    container = ""
    options = ""

    def get_prefix(self):
        prefix = None
        if self.container == "ENUMERATION":
            prefix = "enum class "
        elif self.container == "SELECT":
            prefix = "using"
        return prefix


    def convert(self):
        pass

"""Entity converter"""
class EntityConverter(AbsConverter):
    def convert(self):
        pass

"""Functions"""
def write_cpp_types(buf, file):
    print(buf)

def write_cpp_entities(buf, file):
    pass

def convert_ifc_schema(ifc_schema, cpp_type, cpp_entity):
    buf_t = ""
    buf_e = ""

    with open(ifc_schema, 'r') as file:
        f = ConverterFactory()
        block = None
        is_type = True
        for line in file:
            if line.startswith(_Type):
                is_type = True
                block = line
            elif line.startswith(_Entity):
                is_type = False
                block = line
            elif block is not None:
                if line.startswith(_End):
                    c = f.get_converter(block)
                    if c is not None:
                        c.convert()
                        if c.output is not None:
                            if is_type:
                                buf_t += c.output + "\n"
                            else:
                                buf_e += c.output + "\n\n"
                    block = None
                else:
                    block += line

"""
        with open(cpp_type, 'w') as file:
            file.write(buf_t)
"""

"""Main"""
convert_ifc_schema(_IfcSchemaFile, _CppTypeFile, _CppEntityFile)
