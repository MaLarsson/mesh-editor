IfcVersion = "IFC4X1"
IfcSchema = IfcVersion + ".exp";

# private globals
_Type = "TYPE"
_Entity = "ENTITY"
_EndEntity = "END_ENTITY"

# TYPE: REAL, INTEGER, STRING, ENUMERATION OF
# ENTITY: SUBTYPE OF

def parse_ifc_schema(filename):
    with open(filename, 'r') as file:
        curr_block = ""
        for idx, line in enumerate(file):
            if line.startswith(_Type):
                parse_ifc_type(line)
            elif line.startswith(_Entity):
                curr_block += line
            elif line.startswith(_EndEntity):
                parse_ifc_entity(curr_block)
                curr_block = ""
            else:
                curr_block += line

def parse_ifc_type(string):
    return None
    #print(string)

def parse_ifc_entity(string):
    return None
    #print(string)

parse_ifc_schema(IfcSchema)
