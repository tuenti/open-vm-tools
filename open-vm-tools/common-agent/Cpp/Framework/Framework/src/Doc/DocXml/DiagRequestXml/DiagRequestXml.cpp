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

#include "Doc/DocXml/CafCoreTypesXml/RequestHeaderXml.h"
#include "Doc/DocXml/DiagTypesXml/DiagBatchXml.h"

#include "Doc/CafCoreTypesDoc/CRequestHeaderDoc.h"
#include "Doc/DiagRequestDoc/CDiagRequestDoc.h"
#include "Doc/DiagTypesDoc/CDiagBatchDoc.h"
#include "Xml/XmlUtils/CXmlElement.h"
#include "Doc/DocXml/DiagRequestXml/DiagRequestXml.h"

using namespace Caf;

void DiagRequestXml::add(
	const SmartPtrCDiagRequestDoc diagRequestDoc,
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("DiagRequestXml", "add");

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(diagRequestDoc);
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string clientIdVal =
			BasePlatform::UuidToString(diagRequestDoc->getClientId());
		CAF_CM_VALIDATE_STRING(clientIdVal);
		thisXml->addAttribute("clientId", clientIdVal);

		const std::string requestIdVal =
			BasePlatform::UuidToString(diagRequestDoc->getRequestId());
		CAF_CM_VALIDATE_STRING(requestIdVal);
		thisXml->addAttribute("requestId", requestIdVal);

		const std::string pmeIdVal = diagRequestDoc->getPmeId();
		CAF_CM_VALIDATE_STRING(pmeIdVal);
		thisXml->addAttribute("pmeId", pmeIdVal);

		const SmartPtrCRequestHeaderDoc requestHeaderVal =
			diagRequestDoc->getRequestHeader();
		CAF_CM_VALIDATE_SMARTPTR(requestHeaderVal);

		const SmartPtrCXmlElement requestHeaderXml =
			thisXml->createAndAddElement("requestHeader");
		RequestHeaderXml::add(requestHeaderVal, requestHeaderXml);

		const SmartPtrCDiagBatchDoc batchVal =
			diagRequestDoc->getBatch();
		CAF_CM_VALIDATE_SMARTPTR(batchVal);

		const SmartPtrCXmlElement batchXml =
			thisXml->createAndAddElement("batch");
		DiagBatchXml::add(batchVal, batchXml);
	}
	CAF_CM_EXIT;
}

SmartPtrCDiagRequestDoc DiagRequestXml::parse(
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("DiagRequestXml", "parse");

	SmartPtrCDiagRequestDoc diagRequestDoc;

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string clientIdStrVal =
			thisXml->findRequiredAttribute("clientId");
		UUID clientIdVal = CAFCOMMON_GUID_NULL;
		if (! clientIdStrVal.empty()) {
			BasePlatform::UuidFromString(clientIdStrVal.c_str(), clientIdVal);
		}

		const std::string requestIdStrVal =
			thisXml->findRequiredAttribute("requestId");
		UUID requestIdVal = CAFCOMMON_GUID_NULL;
		if (! requestIdStrVal.empty()) {
			BasePlatform::UuidFromString(requestIdStrVal.c_str(), requestIdVal);
		}

		const std::string pmeIdVal =
			thisXml->findRequiredAttribute("pmeId");

		const SmartPtrCXmlElement requestHeaderXml =
			thisXml->findRequiredChild("requestHeader");

		SmartPtrCRequestHeaderDoc requestHeaderVal;
		if (! requestHeaderXml.IsNull()) {
			requestHeaderVal = RequestHeaderXml::parse(requestHeaderXml);
		}

		const SmartPtrCXmlElement batchXml =
			thisXml->findRequiredChild("batch");

		SmartPtrCDiagBatchDoc batchVal;
		if (! batchXml.IsNull()) {
			batchVal = DiagBatchXml::parse(batchXml);
		}

		diagRequestDoc.CreateInstance();
		diagRequestDoc->initialize(
			clientIdVal,
			requestIdVal,
			pmeIdVal,
			requestHeaderVal,
			batchVal);
	}
	CAF_CM_EXIT;

	return diagRequestDoc;
}

