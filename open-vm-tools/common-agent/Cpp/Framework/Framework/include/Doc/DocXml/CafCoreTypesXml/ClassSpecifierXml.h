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

#ifndef ClassSpecifierXml_h_
#define ClassSpecifierXml_h_


#include "Doc/CafCoreTypesDoc/CClassSpecifierDoc.h"

#include "Doc/DocXml/CafCoreTypesXml/CafCoreTypesXmlLink.h"
#include "Xml/XmlUtils/CXmlElement.h"

namespace Caf {

	/// Streams the ClassSpecifier class to/from XML
	namespace ClassSpecifierXml {

		/// Adds the ClassSpecifierDoc into the XML.
		void CAFCORETYPESXML_LINKAGE add(
			const SmartPtrCClassSpecifierDoc classSpecifierDoc,
			const SmartPtrCXmlElement thisXml);

		/// Parses the ClassSpecifierDoc from the XML.
		SmartPtrCClassSpecifierDoc CAFCORETYPESXML_LINKAGE parse(
			const SmartPtrCXmlElement thisXml);
	}
}

#endif
