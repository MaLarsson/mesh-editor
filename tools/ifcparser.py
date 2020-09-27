"""Convert IFC types and entities to C++ types"""

"""Globals"""
_IfcVersion = "IFC4X1"
_IfcSchemaFile = _IfcVersion + ".exp"
_CppTypeFile = "type.h"
_CppEntityFile = "entity.h"
_Type = "TYPE"
_Entity = "ENTITY"
_EndEntity = "END_ENTITY"
_Containers = ["ARRAY", "LIST", "SET", "SELECT"]
_TypeMap = {
    "BOOLEAN": "bool",
    "NUMBER": "double",
    "REAL": "double",
    "INTEGER": "int",
    "BINARY": "std::vector<std::byte>",
    "STRING": "std::string",
    "LIST": "std::vector",
    "SET": "std::unordered_set",
    "SELECT": "std::variant"
}

"""Classes"""
# FACTORY
class AbsConverterFactory:
    def get_converter(self, block):
        converter = None
        if block.startswith(_Type):
            tokens = block[0:-2].split()
            name = tokens[1]
            type = tokens[-1]
            container = tokens[3]
            if type == "ENUMERATION":
                converter = EnumTypeConverter()
            elif container in _Containers:
                converter = ContainerTypeConverter(name, type, container)
            else:
                converter = BasicTypeConverter(name, type)
        elif block.startswith(_Entity):
            converter = EntityConverter()

        if converter is None:
            print("Failed to get converter for -\n" + block)

        return converter

# ABSTRACT CONVERTER
class AbsConverter:
    output = None
    def convert(self):
        pass

# REAL, INTEGER, STRING, IFC TYPE
class BasicTypeConverter(AbsConverter):
    name = ""
    type = ""
    prefix = "using"

    def __init__(self, name, type):
        self.name = name
        self.type = type

    def convert(self):
        t = None
        try:
            t = _TypeMap[self.type]
        except KeyError:
            if self.type.startswith("Ifc"): t = self.type

        if t is None:
            print("Failed to get type for: " + self.type)
        else:
            self.output = self.prefix + " " + self.name + " " + t + ";"


class ContainerTypeConverter(BasicTypeConverter):
    container = ""

    def __init__(self, name, type, container):
        super().__init__(name, type)
        self.container = container

    def convert(self):
        pass


class EnumTypeConverter(AbsConverter):
    def convert(self):
        pass

# ENTITY
class EntityConverter(AbsConverter):
    def convert(self):
        pass



"""Functions"""
def write_cpp_types(buf, file):
    print(buf)

def write_cpp_entities(buf, file):
    pass

def convert_ifc_schema(ifc_schema, cpp_type, cpp_entity):
    with open(ifc_schema, 'r') as file:
        f = AbsConverterFactory()
        buf_t = ""
        buf_e = ""
        block = None
        state = 0
        for line in file:
            if line.startswith(_Type):
                block = line
                state = 1
            if line.startswith(_Entity):
                block = line
            elif line.startswith(_EndEntity):
                state = 2
            elif block is not None:
                block += line

            if state > 0:
                c = f.get_converter(block)
                c.convert()
                if c.output is not None:
                    if state == 1:
                        buf_t += c.output
                    elif state == 2:
                        buf_e += c.output
                state = 0
                block = None

"""Main"""
convert_ifc_schema(_IfcSchemaFile, _CppTypeFile, _CppEntityFile)
