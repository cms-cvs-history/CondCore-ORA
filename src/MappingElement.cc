#include "CondCore/ORA/interface/Exception.h"
#include "MappingElement.h"
//
#include <set>
#include <sstream>

std::string
ora::MappingElement::classMappingElementType()
{
  static std::string s_classMappingElementType = "Class";
  return s_classMappingElementType;
}

std::string
ora::MappingElement::objectMappingElementType()
{
  static std::string s_objectMappingElementType = "Object";
  return s_objectMappingElementType;
}

std::string
ora::MappingElement::dependencyMappingElementType()
{
  static std::string s_dependencyMappingElementType = "Dependency";
  return s_dependencyMappingElementType;
}

std::string
ora::MappingElement::primitiveMappingElementType()
{
  static std::string s_primitiveMappingElementType = "Primitive";
  return s_primitiveMappingElementType;
}

std::string
ora::MappingElement::arrayMappingElementType()
{
  static std::string s_arrayMappingElementType = "Array";
  return s_arrayMappingElementType;
}

std::string
ora::MappingElement::CArrayMappingElementType()
{
  static std::string s_CArrayMappingElementType = "CArray";
  return s_CArrayMappingElementType;
}

std::string
ora::MappingElement::inlineCArrayMappingElementType()
{
  static std::string s_inlineCArrayMappingElementType = "InlineCArray";
  return s_inlineCArrayMappingElementType;
}

std::string
ora::MappingElement::OraReferenceMappingElementType()
{
  static std::string s_oraReferenceMappingElementType = "OraReference";
  return s_oraReferenceMappingElementType;
}

std::string
ora::MappingElement::OraPointerMappingElementType()
{
  static std::string s_oraPointerMappingElementType = "OraPointer";
  return s_oraPointerMappingElementType;
}

std::string
ora::MappingElement::uniqueReferenceMappingElementType()
{
  static std::string s_oraUniqueReferenceMappingElementType = "UniqueReference";
  return s_oraUniqueReferenceMappingElementType;
}

std::string
ora::MappingElement::OraArrayMappingElementType()
{
  static std::string s_oraArrayMappingElementType = "OraArray";
  return s_oraArrayMappingElementType;
}

std::string
ora::MappingElement::pointerMappingElementType()
{
  static std::string s_pointerMappingElementType = "Pointer";
  return s_pointerMappingElementType;
}

std::string
ora::MappingElement::referenceMappingElementType()
{
  static std::string s_referenceMappingElementType = "Reference";
  return s_referenceMappingElementType;
}

std::string
ora::MappingElement::blobMappingElementType()
{
  static std::string s_blobMappingElementType = "Blob";
  return s_blobMappingElementType;
}

bool
ora::MappingElement::isValidMappingElementType( const std::string& elementType )
{
  return ( elementType == classMappingElementType() ||
           elementType == objectMappingElementType() ||
           elementType == dependencyMappingElementType() ||
           elementType == primitiveMappingElementType() ||
           elementType == arrayMappingElementType() ||
           elementType == CArrayMappingElementType() ||
           elementType == inlineCArrayMappingElementType() ||
           elementType == OraReferenceMappingElementType() ||
           elementType == OraPointerMappingElementType() ||
           elementType == uniqueReferenceMappingElementType() ||
           elementType == OraArrayMappingElementType() ||
           elementType == pointerMappingElementType() ||
           elementType == referenceMappingElementType() ||
           elementType == blobMappingElementType() );
}

std::string
ora::MappingElement::elementTypeAsString( ora::MappingElement::ElementType elementType )
{
  switch ( elementType ) {
  case Class :
    return  classMappingElementType();
    break;
  case Object :
    return  objectMappingElementType();
    break;
  case Dependency :
    return  dependencyMappingElementType();
    break;
  case Primitive :
    return  primitiveMappingElementType();
    break;
  case Array :
    return  arrayMappingElementType();
    break;
  case CArray :
    return  CArrayMappingElementType();
    break;
  case InlineCArray :
    return  inlineCArrayMappingElementType();
    break;
  case OraReference :
    return  OraReferenceMappingElementType();
    break;
  case OraPointer :
    return  OraPointerMappingElementType();
    break;
  case UniqueReference :
    return  uniqueReferenceMappingElementType();
    break;
  case OraArray :
    return  OraArrayMappingElementType();
    break;
  case Reference :
    return  referenceMappingElementType();
    break;
  case Blob :
    return  blobMappingElementType();
    break;
  case Pointer :
    return  pointerMappingElementType();
    break;
  case Undefined :
    // This should never appear
    break;
  };

  throwException( "Undefined mapping element type",
                  "MappingElement::elementTypeAsString" );
  return "";
}


ora::MappingElement::ElementType
ora::MappingElement::elementTypeFromString( const std::string& elementType )
{
  // Check here the element type
  if ( !  isValidMappingElementType( elementType ) ) {
    throwException( "\"" + elementType + "\" is not a supported mapping element type",
                    "MappingElement::elementTypeFromString" );
  }

  ora::MappingElement::ElementType result = Undefined;

  if ( elementType == classMappingElementType() ) {
    return Class;
  }
  if ( elementType == objectMappingElementType() ) {
    return Object;
  }
  if ( elementType == dependencyMappingElementType() ) {
    return Dependency;
  }
  if ( elementType == primitiveMappingElementType() ) {
    return Primitive;
  }
  else if ( elementType == arrayMappingElementType() ) {
    return Array;
  }
  else if ( elementType == CArrayMappingElementType() ) {
    return CArray;
  }
  else if ( elementType == inlineCArrayMappingElementType() ) {
    return InlineCArray;
  }
  else if ( elementType == pointerMappingElementType() ) {
    return Pointer;
  }
  else if ( elementType == referenceMappingElementType() ) {
    return Reference;
  }
  else if ( elementType == OraReferenceMappingElementType() ) {
    return OraReference;
  }
  else if ( elementType == OraPointerMappingElementType() ) {
    return OraPointer;
  }
  else if ( elementType == uniqueReferenceMappingElementType() ) {
    return UniqueReference;
  }
  else if ( elementType == OraArrayMappingElementType() ) {
    return OraArray;
  }
  else if ( elementType == blobMappingElementType() ) {
    return Blob;
  }

  return result;
}

ora::MappingElement::MappingElement( const std::string& elementType,
                                     const std::string& variableName,
                                     const std::string& variableType,
                                     const std::string& tableName ):
  m_elementType( Undefined ),
  m_parentType( Undefined ),
  m_isDependentTree(false),
  m_scopeName( "" ),
  m_variableName( variableName ),
  m_variableNameForSchema( "" ),
  m_variableNameForColumn( "" ),
  m_variableType( variableType ),
  m_tableName( tableName ),
  m_columnNames(),
  m_subElements(),
  m_mainTableName( tableName ),
  m_parentClassMappingElement()
{
  // Check here the element type
  if ( !  isValidMappingElementType( elementType ) ) {
    throwException( "\"" + elementType + "\" is not a supported mapping element type",
                    "MappingElement::MappingElement" );
  }
  m_elementType = elementTypeFromString( elementType );
  if(m_elementType == Dependency) m_isDependentTree = true;
}

ora::MappingElement::~MappingElement() {
}

size_t ora::MappingElement::startIndexForPKColumns() const {
  size_t startIndex = 0;
  if( m_isDependentTree ) startIndex = 1;
  return startIndex;
}

namespace ora {
  void processTableHierarchy( const MappingElement& element,
                              std::set<std::string>& tableRegister,
                              std::vector<std::pair<std::string, std::string> >& tableList ){
    const std::string& tableName = element.tableName();
    std::set<std::string>::iterator iT = tableRegister.find( tableName );
    if( iT == tableRegister.end() ){
      tableRegister.insert( tableName );
      tableList.push_back( std::make_pair(tableName,element.columnNames()[0]) );
    }
    for(MappingElement::const_iterator iEl = element.begin();
        iEl != element.end(); ++iEl ){
      processTableHierarchy( iEl->second, tableRegister, tableList );
    }
  }
}

std::vector<std::pair<std::string,std::string> >
ora::MappingElement::tableHierarchy() const{
  std::set<std::string> involvedTables;
  std::vector<std::pair<std::string,std::string> > tableList;
  processTableHierarchy( *this, involvedTables,tableList );
  return tableList;
}

void
ora::MappingElement::setDependency( const MappingElement& parentClassMappingElement )
{
  m_elementType = Dependency;
  m_isDependentTree = true;
  m_parentClassMappingElement.reset( new MappingElement( parentClassMappingElement) );
}

ora::MappingElement&
ora::MappingElement::appendSubElement( const std::string& elementType,
                                       const std::string& variableName,
                                       const std::string& variableType,
                                       const std::string& tableName )
{
  // Check whether the current element type supports other subelements
  if ( ! ( m_elementType == Class ||
           m_elementType == Object ||
           m_elementType == Dependency ||
           m_elementType == Array ||
           m_elementType == CArray ||
           m_elementType == InlineCArray ||
           m_elementType == OraReference ||
           m_elementType == OraPointer ||
           m_elementType == OraArray ) ) {
    throwException( "Attempted to insert a sub-element under an element of type \"" +
                    ora::MappingElement::elementTypeAsString( m_elementType ) + "\"",
                    "MappingElement::appendSubElement" );
  }
  MappingElement& newElement =
    m_subElements.insert( std::make_pair( variableName,ora::MappingElement( elementType,
                                                                            variableName,
                                                                            variableType,
                                                                            tableName ) ) ).first->second;
  newElement.m_parentType = m_elementType;
  newElement.m_isDependentTree = m_isDependentTree;
  if ( m_scopeName.empty() ) {
    newElement.m_scopeName = m_variableName;
  } else {
    newElement.m_scopeName = m_scopeName + "::" + m_variableName;
  }
  newElement.m_mainTableName = m_mainTableName;
  
  return newElement;
}

void
ora::MappingElement::appendSubElementTree( const MappingElement& element ){
  if ( ! ( m_elementType == Class ||
           m_elementType == Object ||
           m_elementType == Dependency||
           m_elementType == Array ||
           m_elementType == CArray ||
           m_elementType == InlineCArray ||
           m_elementType == OraReference ||
           m_elementType == OraPointer ||
           m_elementType == OraArray  ) ) {
    throwException( "Attempted to insert a sub-element under an element of type \"" +
                    MappingElement::elementTypeAsString( m_elementType ) + "\"",
                    "MappingElement::appendSubElement" );
  }
  m_subElements.insert( std::make_pair(element.variableName(),element));
}

void
ora::MappingElement::alterType( const std::string& elementType )
{
  // Check here the element type
  if ( !  isValidMappingElementType( elementType ) ) {
    throwException( "\"" + elementType + "\" is not a supported mapping element type",
                    "MappingElement::alterType");
  }
  ElementType elementTypeCode = elementTypeFromString( elementType );
  if(m_elementType != elementTypeCode){
    m_elementType = elementTypeCode;      
    // clear sub elements when no supported by the new type specified
    if ( ! ( m_elementType == Class ||
             m_elementType == Object ||
             m_elementType == Dependency ||
             m_elementType == Array ||
             m_elementType == CArray ||
             m_elementType == OraReference ||
             m_elementType == OraPointer ||
             m_elementType == OraArray  ) ) {
      m_subElements.clear();
    }
  }
}

void
ora::MappingElement::alterTableName( const std::string& tableName )
{
  if ( tableName == m_tableName ) return;

  for ( iterator iElement = this->begin();
        iElement != this->end(); ++iElement ) {
    ora::MappingElement& subElement = iElement->second;
    if ( subElement.elementType() != Array &&
         subElement.elementType() != CArray &&
         subElement.elementType() != OraPointer &&
         subElement.elementType() != OraArray  ) {
      subElement.alterTableName( tableName );
    }
  }
  m_tableName = tableName;
}

void
ora::MappingElement::setVariableNameForSchema(const std::string& scopeName,
                                                               const std::string& variableName,
                                                               bool embeddedObject){
  if ( scopeName.empty() ) {
    m_variableNameForSchema = variableName;
  } else {
    m_variableNameForSchema = scopeName + "_" + variableName;
  }
  if(embeddedObject) m_variableNameForColumn = variableName;
}

void
ora::MappingElement::setColumnNames( const std::vector< std::string >& columns )
{
  m_columnNames = columns;
  if ( m_subElements.empty() ) return;

  std::vector< std::string > columnsToPropagate = m_columnNames;
  if ( this->elementType() == OraReference ) {
    // Remove the OID fields
    columnsToPropagate.pop_back();
    columnsToPropagate.pop_back();
  }

  for ( iterator iElement = this->begin();
        iElement != this->end(); ++iElement ) {
    ora::MappingElement& subElement = iElement->second;

    if ( subElement.elementType() == Object &&
         subElement.tableName() == m_tableName ) {
      subElement.setColumnNames( columnsToPropagate );
    }
    else if ( subElement.elementType() == OraReference &&
              subElement.tableName() == m_tableName ) {
      std::vector< std::string > columns = subElement.columnNames();
      for ( size_t i = 0; i < columns.size() - 2; ++i ) columns[i] = columnsToPropagate[i];
      subElement.setColumnNames( columns );
    }
  }
}

void ora::MappingElement::override(const MappingElement& source)
{
  if(variableType()==source.variableType() || elementType()==source.elementType())
  {
    alterType(MappingElement::elementTypeAsString(source.elementType()));
    alterTableName(source.tableName());
    setColumnNames(source.columnNames());
    for(iterator iel=begin();
        iel!=end();++iel){
      const_iterator iTarg = source.find(iel->first);
      if(iTarg!=source.end()){
        iel->second.override(iTarg->second);
      }
    }
  }  

}
