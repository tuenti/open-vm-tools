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

#ifndef DiagSetValueCollectionXml_h_
#define DiagSetValueCollectionXml_h_


#include "Doc/DiagTypesDoc/CDiagSetValueCollectionDoc.h"

#include "Doc/DocXml/DiagTypesXml/DiagTypesXmlLink.h"
#include "Xml/XmlUtils/CXmlElement.h"

namespace Caf {

	/// Streams the DiagSetValueCollection class to/from XML
	namespace DiagSetValueCollectionXml {

		/// Adds the DiagSetValueCollectionDoc into the XML.
		void DIAGTYPESXML_LINKAGE add(
			const SmartPtrCDiagSetValueCollectionDoc diagSetValueCollectionDoc,
			const SmartPtrCXmlElement thisXml);

		/// Parses the DiagSetValueCollectionDoc from the XML.
		SmartPtrCDiagSetValueCollectionDoc DIAGTYPESXML_LINKAGE parse(
			const SmartPtrCXmlElement thisXml);
	}
}

#endif
