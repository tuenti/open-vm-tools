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

#ifndef AddInsXml_h_
#define AddInsXml_h_


#include "Doc/CafCoreTypesDoc/CAddInsDoc.h"

#include "Doc/DocXml/CafCoreTypesXml/CafCoreTypesXmlLink.h"
#include "Xml/XmlUtils/CXmlElement.h"

namespace Caf {

	/// Streams the AddIns class to/from XML
	namespace AddInsXml {

		/// Adds the AddInsDoc into the XML.
		void CAFCORETYPESXML_LINKAGE add(
			const SmartPtrCAddInsDoc addInsDoc,
			const SmartPtrCXmlElement thisXml);

		/// Parses the AddInsDoc from the XML.
		SmartPtrCAddInsDoc CAFCORETYPESXML_LINKAGE parse(
			const SmartPtrCXmlElement thisXml);
	}
}

#endif
