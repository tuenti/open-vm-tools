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

#include "Doc/DocUtils/EnumConvertersXml.h"
#include "Doc/CafCoreTypesDoc/CafCoreTypesDocTypes.h"

#include "Doc/CafCoreTypesDoc/CAttachmentDoc.h"
#include "Xml/XmlUtils/CXmlElement.h"
#include "Doc/DocXml/CafCoreTypesXml/AttachmentXml.h"

using namespace Caf;

void AttachmentXml::add(
	const SmartPtrCAttachmentDoc attachmentDoc,
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("AttachmentXml", "add");

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(attachmentDoc);
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string nameVal = attachmentDoc->getName();
		CAF_CM_VALIDATE_STRING(nameVal);
		thisXml->addAttribute("name", nameVal);

		const std::string typeVal = attachmentDoc->getType();
		CAF_CM_VALIDATE_STRING(typeVal);
		thisXml->addAttribute("type", typeVal);

		const std::string uriVal = attachmentDoc->getUri();
		CAF_CM_VALIDATE_STRING(uriVal);
		thisXml->addAttribute("uri", uriVal);

		const std::string isReferenceVal = attachmentDoc->getIsReference() ? "true" : "false";
		CAF_CM_VALIDATE_STRING(isReferenceVal);
		thisXml->addAttribute("isReference", isReferenceVal);

		const CMS_POLICY cmsPolicyVal = attachmentDoc->getCmsPolicy();
		thisXml->addAttribute("cmsPolicy", EnumConvertersXml::convertCmsPolicyToString(cmsPolicyVal));
	}
	CAF_CM_EXIT;
}

SmartPtrCAttachmentDoc AttachmentXml::parse(
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("AttachmentXml", "parse");

	SmartPtrCAttachmentDoc attachmentDoc;

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string nameStrVal =
			thisXml->findRequiredAttribute("name");
		const std::string nameVal = nameStrVal;

		const std::string typeStrVal =
			thisXml->findRequiredAttribute("type");
		const std::string typeVal = typeStrVal;

		const std::string uriStrVal =
			thisXml->findRequiredAttribute("uri");
		const std::string uriVal = uriStrVal;

		const std::string isReferenceStrVal =
			thisXml->findRequiredAttribute("isReference");
		bool isReferenceVal = false;
		if (! isReferenceStrVal.empty()) {
			isReferenceVal = (isReferenceStrVal.compare("true") == 0)  ? true : false;
		}

		CMS_POLICY cmsPolicyVal = CMS_POLICY_NONE;
		const std::string cmsPolicyStr = thisXml->findOptionalAttribute("cmsPolicy");
		if (! cmsPolicyStr.empty()) {
			cmsPolicyVal = EnumConvertersXml::convertStringToCmsPolicy(cmsPolicyStr);
		}

		attachmentDoc.CreateInstance();
		attachmentDoc->initialize(
			nameVal,
			typeVal,
			uriVal,
			isReferenceVal,
			cmsPolicyVal);
	}
	CAF_CM_EXIT;

	return attachmentDoc;
}

