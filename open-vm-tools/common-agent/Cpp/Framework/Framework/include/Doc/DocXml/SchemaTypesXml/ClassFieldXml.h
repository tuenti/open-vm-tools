/*
 *  Author: bwilliams
 *  Created: April 6, 2012
 *
 *  Copyright (c) 2012 Vmware, Inc.  All rights reserved.
 *  -- VMware Confidential
 *
 *  This code was generated by the script "build/dev/codeGen/genCppXml". Please
 *  speak to Brian W. before modifying it by hand.
 *
 */

#ifndef ClassFieldXml_h_
#define ClassFieldXml_h_


#include "Doc/SchemaTypesDoc/CClassFieldDoc.h"

#include "Doc/DocXml/SchemaTypesXml/SchemaTypesXmlLink.h"
#include "Xml/XmlUtils/CXmlElement.h"

namespace Caf {

	/// Streams the ClassField class to/from XML
	namespace ClassFieldXml {

		/// Adds the ClassFieldDoc into the XML.
		void SCHEMATYPESXML_LINKAGE add(
			const SmartPtrCClassFieldDoc classFieldDoc,
			const SmartPtrCXmlElement thisXml);

		/// Parses the ClassFieldDoc from the XML.
		SmartPtrCClassFieldDoc SCHEMATYPESXML_LINKAGE parse(
			const SmartPtrCXmlElement thisXml);
	}
}

#endif
