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

#ifndef DiagCollectInstancesXml_h_
#define DiagCollectInstancesXml_h_


#include "Doc/DiagTypesDoc/CDiagCollectInstancesDoc.h"

#include "Doc/DocXml/DiagTypesXml/DiagTypesXmlLink.h"
#include "Xml/XmlUtils/CXmlElement.h"

namespace Caf {

	/// Streams the DiagCollectInstances class to/from XML
	namespace DiagCollectInstancesXml {

		/// Adds the DiagCollectInstancesDoc into the XML.
		void DIAGTYPESXML_LINKAGE add(
			const SmartPtrCDiagCollectInstancesDoc diagCollectInstancesDoc,
			const SmartPtrCXmlElement thisXml);

		/// Parses the DiagCollectInstancesDoc from the XML.
		SmartPtrCDiagCollectInstancesDoc DIAGTYPESXML_LINKAGE parse(
			const SmartPtrCXmlElement thisXml);
	}
}

#endif
