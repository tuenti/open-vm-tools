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

#ifndef MultiPmeMgmtBatchCollectionXml_h_
#define MultiPmeMgmtBatchCollectionXml_h_


#include "Doc/MultiPmeMgmtRequestDoc/CMultiPmeMgmtBatchCollectionDoc.h"

#include "Doc/DocXml/MultiPmeMgmtRequestXml/MultiPmeMgmtRequestXmlLink.h"
#include "Xml/XmlUtils/CXmlElement.h"

namespace Caf {

	/// Streams the MultiPmeMgmtBatchCollection class to/from XML
	namespace MultiPmeMgmtBatchCollectionXml {

		/// Adds the MultiPmeMgmtBatchCollectionDoc into the XML.
		void MULTIPMEMGMTREQUESTXML_LINKAGE add(
			const SmartPtrCMultiPmeMgmtBatchCollectionDoc multiPmeMgmtBatchCollectionDoc,
			const SmartPtrCXmlElement thisXml);

		/// Parses the MultiPmeMgmtBatchCollectionDoc from the XML.
		SmartPtrCMultiPmeMgmtBatchCollectionDoc MULTIPMEMGMTREQUESTXML_LINKAGE parse(
			const SmartPtrCXmlElement thisXml);
	}
}

#endif
