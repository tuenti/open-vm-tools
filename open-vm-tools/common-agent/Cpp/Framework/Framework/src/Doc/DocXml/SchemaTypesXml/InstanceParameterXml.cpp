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

#include "Doc/SchemaTypesDoc/CInstanceParameterDoc.h"
#include "Xml/XmlUtils/CXmlElement.h"
#include "Doc/DocXml/SchemaTypesXml/InstanceParameterXml.h"

using namespace Caf;

void InstanceParameterXml::add(
	const SmartPtrCInstanceParameterDoc instanceParameterDoc,
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("InstanceParameterXml", "add");

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(instanceParameterDoc);
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string nameVal = instanceParameterDoc->getName();
		CAF_CM_VALIDATE_STRING(nameVal);
		thisXml->addAttribute("name", nameVal);

		const std::string instanceNamespaceVal = instanceParameterDoc->getInstanceNamespace();
		CAF_CM_VALIDATE_STRING(instanceNamespaceVal);
		thisXml->addAttribute("instanceNamespace", instanceNamespaceVal);

		const std::string instanceNameVal = instanceParameterDoc->getInstanceName();
		CAF_CM_VALIDATE_STRING(instanceNameVal);
		thisXml->addAttribute("instanceName", instanceNameVal);

		const std::string instanceVersionVal = instanceParameterDoc->getInstanceVersion();
		CAF_CM_VALIDATE_STRING(instanceVersionVal);
		thisXml->addAttribute("instanceVersion", instanceVersionVal);

		const std::string isOptionalVal = instanceParameterDoc->getIsOptional() ? "true" : "false";
		CAF_CM_VALIDATE_STRING(isOptionalVal);
		thisXml->addAttribute("isOptional", isOptionalVal);

		const std::string isListVal = instanceParameterDoc->getIsList() ? "true" : "false";
		if (! isListVal.empty()) {
			thisXml->addAttribute("isList", isListVal);
		}

		const std::string displayNameVal = instanceParameterDoc->getDisplayName();
		if (! displayNameVal.empty()) {
			thisXml->addAttribute("displayName", displayNameVal);
		}

		const std::string descriptionVal = instanceParameterDoc->getDescription();
		if (! descriptionVal.empty()) {
			thisXml->addAttribute("description", descriptionVal);
		}
	}
	CAF_CM_EXIT;
}

SmartPtrCInstanceParameterDoc InstanceParameterXml::parse(
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("InstanceParameterXml", "parse");

	SmartPtrCInstanceParameterDoc instanceParameterDoc;

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string nameStrVal =
			thisXml->findRequiredAttribute("name");
		const std::string nameVal = nameStrVal;

		const std::string instanceNamespaceStrVal =
			thisXml->findRequiredAttribute("instanceNamespace");
		const std::string instanceNamespaceVal = instanceNamespaceStrVal;

		const std::string instanceNameStrVal =
			thisXml->findRequiredAttribute("instanceName");
		const std::string instanceNameVal = instanceNameStrVal;

		const std::string instanceVersionStrVal =
			thisXml->findRequiredAttribute("instanceVersion");
		const std::string instanceVersionVal = instanceVersionStrVal;

		const std::string isOptionalStrVal =
			thisXml->findRequiredAttribute("isOptional");
		bool isOptionalVal = false;
		if (! isOptionalStrVal.empty()) {
			isOptionalVal = (isOptionalStrVal.compare("true") == 0)  ? true : false;
		}

		const std::string isListStrVal =
			thisXml->findOptionalAttribute("isList");
		bool isListVal = false;
		if (! isListStrVal.empty()) {
			isListVal = (isListStrVal.compare("true") == 0)  ? true : false;
		}

		const std::string displayNameStrVal =
			thisXml->findOptionalAttribute("displayName");
		const std::string displayNameVal = displayNameStrVal;

		const std::string descriptionStrVal =
			thisXml->findOptionalAttribute("description");
		const std::string descriptionVal = descriptionStrVal;

		instanceParameterDoc.CreateInstance();
		instanceParameterDoc->initialize(
			nameVal,
			instanceNamespaceVal,
			instanceNameVal,
			instanceVersionVal,
			isOptionalVal,
			isListVal,
			displayNameVal,
			descriptionVal);
	}
	CAF_CM_EXIT;

	return instanceParameterDoc;
}

