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

#include "Doc/DocXml/CafCoreTypesXml/AttachmentNameCollectionXml.h"

#include "Doc/CafCoreTypesDoc/CAttachmentNameCollectionDoc.h"
#include "Doc/ResponseDoc/CManifestDoc.h"
#include "Xml/XmlUtils/CXmlElement.h"
#include "Doc/DocXml/ResponseXml/ManifestXml.h"

using namespace Caf;

void ManifestXml::add(
	const SmartPtrCManifestDoc manifestDoc,
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("ManifestXml", "add");

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(manifestDoc);
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string classNamespaceVal = manifestDoc->getClassNamespace();
		CAF_CM_VALIDATE_STRING(classNamespaceVal);
		thisXml->addAttribute("classNamespace", classNamespaceVal);

		const std::string classNameVal = manifestDoc->getClassName();
		CAF_CM_VALIDATE_STRING(classNameVal);
		thisXml->addAttribute("className", classNameVal);

		const std::string classVersionVal = manifestDoc->getClassVersion();
		CAF_CM_VALIDATE_STRING(classVersionVal);
		thisXml->addAttribute("classVersion", classVersionVal);

		const std::string jobIdVal =
			BasePlatform::UuidToString(manifestDoc->getJobId());
		CAF_CM_VALIDATE_STRING(jobIdVal);
		thisXml->addAttribute("jobId", jobIdVal);

		const std::string operationNameVal = manifestDoc->getOperationName();
		CAF_CM_VALIDATE_STRING(operationNameVal);
		thisXml->addAttribute("operationName", operationNameVal);

		const SmartPtrCAttachmentNameCollectionDoc attachmentNameCollectionVal =
			manifestDoc->getAttachmentNameCollection();
		CAF_CM_VALIDATE_SMARTPTR(attachmentNameCollectionVal);

		const SmartPtrCXmlElement attachmentNameCollectionXml =
			thisXml->createAndAddElement("attachmentNameCollection");
		AttachmentNameCollectionXml::add(attachmentNameCollectionVal, attachmentNameCollectionXml);
	}
	CAF_CM_EXIT;
}

SmartPtrCManifestDoc ManifestXml::parse(
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("ManifestXml", "parse");

	SmartPtrCManifestDoc manifestDoc;

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string classNamespaceStrVal =
			thisXml->findRequiredAttribute("classNamespace");
		const std::string classNamespaceVal = classNamespaceStrVal;

		const std::string classNameStrVal =
			thisXml->findRequiredAttribute("className");
		const std::string classNameVal = classNameStrVal;

		const std::string classVersionStrVal =
			thisXml->findRequiredAttribute("classVersion");
		const std::string classVersionVal = classVersionStrVal;

		const std::string jobIdStrVal =
			thisXml->findRequiredAttribute("jobId");
		UUID jobIdVal = CAFCOMMON_GUID_NULL;
		if (! jobIdStrVal.empty()) {
			BasePlatform::UuidFromString(jobIdStrVal.c_str(), jobIdVal);
		}

		const std::string operationNameStrVal =
			thisXml->findRequiredAttribute("operationName");
		const std::string operationNameVal = operationNameStrVal;

		const SmartPtrCXmlElement attachmentNameCollectionXml =
			thisXml->findRequiredChild("attachmentNameCollection");

		SmartPtrCAttachmentNameCollectionDoc attachmentNameCollectionVal;
		if (! attachmentNameCollectionXml.IsNull()) {
			attachmentNameCollectionVal = AttachmentNameCollectionXml::parse(attachmentNameCollectionXml);
		}

		manifestDoc.CreateInstance();
		manifestDoc->initialize(
			classNamespaceVal,
			classNameVal,
			classVersionVal,
			jobIdVal,
			operationNameVal,
			attachmentNameCollectionVal);
	}
	CAF_CM_EXIT;

	return manifestDoc;
}

