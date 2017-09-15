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

#include "stdafx.h"

#include "Doc/DocXml/CafCoreTypesXml/PropertyCollectionXml.h"
#include "Doc/DocXml/ProviderRequestXml/ProviderRequestConfigXml.h"

#include "Doc/CafCoreTypesDoc/CPropertyCollectionDoc.h"
#include "Doc/ProviderRequestDoc/CProviderRequestConfigDoc.h"
#include "Doc/ProviderRequestDoc/CProviderRequestHeaderDoc.h"
#include "Xml/XmlUtils/CXmlElement.h"
#include "Doc/DocXml/ProviderRequestXml/ProviderRequestHeaderXml.h"

using namespace Caf;

void ProviderRequestHeaderXml::add(
	const SmartPtrCProviderRequestHeaderDoc providerRequestHeaderDoc,
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("ProviderRequestHeaderXml", "add");

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(providerRequestHeaderDoc);
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const SmartPtrCProviderRequestConfigDoc requestConfigVal =
			providerRequestHeaderDoc->getRequestConfig();
		CAF_CM_VALIDATE_SMARTPTR(requestConfigVal);

		const SmartPtrCXmlElement requestConfigXml =
			thisXml->createAndAddElement("requestConfig");
		ProviderRequestConfigXml::add(requestConfigVal, requestConfigXml);

		const SmartPtrCPropertyCollectionDoc echoPropertyBagVal =
			providerRequestHeaderDoc->getEchoPropertyBag();
		if (! echoPropertyBagVal.IsNull()) {
			const SmartPtrCXmlElement echoPropertyBagXml =
				thisXml->createAndAddElement("echoPropertyBag");
			PropertyCollectionXml::add(echoPropertyBagVal, echoPropertyBagXml);
		}
	}
	CAF_CM_EXIT;
}

SmartPtrCProviderRequestHeaderDoc ProviderRequestHeaderXml::parse(
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("ProviderRequestHeaderXml", "parse");

	SmartPtrCProviderRequestHeaderDoc providerRequestHeaderDoc;

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const SmartPtrCXmlElement requestConfigXml =
			thisXml->findRequiredChild("requestConfig");

		SmartPtrCProviderRequestConfigDoc requestConfigVal;
		if (! requestConfigXml.IsNull()) {
			requestConfigVal = ProviderRequestConfigXml::parse(requestConfigXml);
		}

		const SmartPtrCXmlElement echoPropertyBagXml =
			thisXml->findOptionalChild("echoPropertyBag");

		SmartPtrCPropertyCollectionDoc echoPropertyBagVal;
		if (! echoPropertyBagXml.IsNull()) {
			echoPropertyBagVal = PropertyCollectionXml::parse(echoPropertyBagXml);
		}

		providerRequestHeaderDoc.CreateInstance();
		providerRequestHeaderDoc->initialize(
			requestConfigVal,
			echoPropertyBagVal);
	}
	CAF_CM_EXIT;

	return providerRequestHeaderDoc;
}

