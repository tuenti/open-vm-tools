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

#ifndef FullyQualifiedClassGroupXml_h_
#define FullyQualifiedClassGroupXml_h_


#include "Doc/CafCoreTypesDoc/CFullyQualifiedClassGroupDoc.h"

#include "Doc/DocXml/CafCoreTypesXml/CafCoreTypesXmlLink.h"
#include "Xml/XmlUtils/CXmlElement.h"

namespace Caf {

	/// Streams the FullyQualifiedClassGroup class to/from XML
	namespace FullyQualifiedClassGroupXml {

		/// Adds the FullyQualifiedClassGroupDoc into the XML.
		void CAFCORETYPESXML_LINKAGE add(
			const SmartPtrCFullyQualifiedClassGroupDoc fullyQualifiedClassGroupDoc,
			const SmartPtrCXmlElement thisXml);

		/// Parses the FullyQualifiedClassGroupDoc from the XML.
		SmartPtrCFullyQualifiedClassGroupDoc CAFCORETYPESXML_LINKAGE parse(
			const SmartPtrCXmlElement thisXml);
	}
}

#endif
