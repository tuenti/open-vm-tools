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

#include "Doc/CafCoreTypesDoc/CAuthnAuthzCollectionDoc.h"
#include "Doc/CafCoreTypesDoc/CPropertyCollectionDoc.h"
#include "Doc/CafCoreTypesDoc/CProtocolCollectionDoc.h"
#include "Doc/CafCoreTypesDoc/CRequestConfigDoc.h"
#include "Doc/CafCoreTypesDoc/CRequestHeaderDoc.h"
#include "Xml/XmlUtils/CXmlElement.h"
#include "Doc/DocXml/CafCoreTypesXml/RequestHeaderXml.h"
#include "Doc/DocXml/CafCoreTypesXml/RequestConfigXml.h"
#include "Doc/DocXml/CafCoreTypesXml/AuthnAuthzCollectionXml.h"
#include "Doc/DocXml/CafCoreTypesXml/ProtocolCollectionXml.h"
#include "Doc/DocXml/CafCoreTypesXml/PropertyCollectionXml.h"

using namespace Caf;

void RequestHeaderXml::add(
	const SmartPtrCRequestHeaderDoc requestHeaderDoc,
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("RequestHeaderXml", "add");

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(requestHeaderDoc);
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const SmartPtrCRequestConfigDoc requestConfigVal =
			requestHeaderDoc->getRequestConfig();
		CAF_CM_VALIDATE_SMARTPTR(requestConfigVal);

		const SmartPtrCXmlElement requestConfigXml =
			thisXml->createAndAddElement("requestConfig");
		RequestConfigXml::add(requestConfigVal, requestConfigXml);

		const SmartPtrCAuthnAuthzCollectionDoc authnAuthzCollectionVal =
			requestHeaderDoc->getAuthnAuthzCollection();
		if (! authnAuthzCollectionVal.IsNull()) {
			const SmartPtrCXmlElement authnAuthzCollectionXml =
				thisXml->createAndAddElement("authnAuthzCollection");
			AuthnAuthzCollectionXml::add(authnAuthzCollectionVal, authnAuthzCollectionXml);
		}

		const SmartPtrCProtocolCollectionDoc protocolCollectionVal =
			requestHeaderDoc->getProtocolCollection();
		if (! protocolCollectionVal.IsNull()) {
			const SmartPtrCXmlElement protocolCollectionXml =
				thisXml->createAndAddElement("protocolCollection");
			ProtocolCollectionXml::add(protocolCollectionVal, protocolCollectionXml);
		}

		const SmartPtrCPropertyCollectionDoc echoPropertyBagVal =
			requestHeaderDoc->getEchoPropertyBag();
		if (! echoPropertyBagVal.IsNull()) {
			const SmartPtrCXmlElement echoPropertyBagXml =
				thisXml->createAndAddElement("echoPropertyBag");
			PropertyCollectionXml::add(echoPropertyBagVal, echoPropertyBagXml);
		}

		const std::string versionVal = requestHeaderDoc->getVersion();
		CAF_CM_VALIDATE_STRING(versionVal);
		thisXml->addAttribute("version", versionVal);

		const std::string createdDateTimeVal = requestHeaderDoc->getCreatedDateTime();
		CAF_CM_VALIDATE_STRING(createdDateTimeVal);
		thisXml->addAttribute("createdDateTime", createdDateTimeVal);

		const std::string sessionIdVal =
			BasePlatform::UuidToString(requestHeaderDoc->getSessionId());
		if (! sessionIdVal.empty()) {
			thisXml->addAttribute("sessionId", sessionIdVal);
		}
	}
	CAF_CM_EXIT;
}

SmartPtrCRequestHeaderDoc RequestHeaderXml::parse(
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("RequestHeaderXml", "parse");

	SmartPtrCRequestHeaderDoc requestHeaderDoc;

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const SmartPtrCXmlElement requestConfigXml =
			thisXml->findRequiredChild("requestConfig");

		SmartPtrCRequestConfigDoc requestConfigVal;
		if (! requestConfigXml.IsNull()) {
			requestConfigVal = RequestConfigXml::parse(requestConfigXml);
		}

		const SmartPtrCXmlElement authnAuthzCollectionXml =
			thisXml->findOptionalChild("authnAuthzCollection");

		SmartPtrCAuthnAuthzCollectionDoc authnAuthzCollectionVal;
		if (! authnAuthzCollectionXml.IsNull()) {
			authnAuthzCollectionVal = AuthnAuthzCollectionXml::parse(authnAuthzCollectionXml);
		}

		const SmartPtrCXmlElement protocolCollectionXml =
			thisXml->findOptionalChild("protocolCollection");

		SmartPtrCProtocolCollectionDoc protocolCollectionVal;
		if (! protocolCollectionXml.IsNull()) {
			protocolCollectionVal = ProtocolCollectionXml::parse(protocolCollectionXml);
		}

		const SmartPtrCXmlElement echoPropertyBagXml =
			thisXml->findOptionalChild("echoPropertyBag");

		SmartPtrCPropertyCollectionDoc echoPropertyBagVal;
		if (! echoPropertyBagXml.IsNull()) {
			echoPropertyBagVal = PropertyCollectionXml::parse(echoPropertyBagXml);
		}

		const std::string versionVal =
			thisXml->findRequiredAttribute("version");

		const std::string createdDateTimeVal =
			thisXml->findRequiredAttribute("createdDateTime");

		const std::string sessionIdStrVal =
			thisXml->findOptionalAttribute("sessionId");
		UUID sessionIdVal = CAFCOMMON_GUID_NULL;
		if (! sessionIdStrVal.empty()) {
			BasePlatform::UuidFromString(sessionIdStrVal.c_str(), sessionIdVal);
		}

		requestHeaderDoc.CreateInstance();
		requestHeaderDoc->initialize(
			requestConfigVal,
			authnAuthzCollectionVal,
			protocolCollectionVal,
			echoPropertyBagVal,
			versionVal,
			createdDateTimeVal,
			sessionIdVal);
	}
	CAF_CM_EXIT;

	return requestHeaderDoc;
}

