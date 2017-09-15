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

#ifndef MethodXml_h_
#define MethodXml_h_


#include "Doc/SchemaTypesDoc/CMethodDoc.h"

#include "Doc/DocXml/SchemaTypesXml/SchemaTypesXmlLink.h"
#include "Xml/XmlUtils/CXmlElement.h"

namespace Caf {

	/// Streams the Method class to/from XML
	namespace MethodXml {

		/// Adds the MethodDoc into the XML.
		void SCHEMATYPESXML_LINKAGE add(
			const SmartPtrCMethodDoc methodDoc,
			const SmartPtrCXmlElement thisXml);

		/// Parses the MethodDoc from the XML.
		SmartPtrCMethodDoc SCHEMATYPESXML_LINKAGE parse(
			const SmartPtrCXmlElement thisXml);
	}
}

#endif
