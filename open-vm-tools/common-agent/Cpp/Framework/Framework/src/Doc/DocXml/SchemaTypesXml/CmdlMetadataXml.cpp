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

#include "Doc/SchemaTypesDoc/CCmdlMetadataDoc.h"
#include "Xml/XmlUtils/CXmlElement.h"
#include "Doc/DocXml/SchemaTypesXml/CmdlMetadataXml.h"

using namespace Caf;

void CmdlMetadataXml::add(
	const SmartPtrCCmdlMetadataDoc cmdlMetadataDoc,
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("CmdlMetadataXml", "add");

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(cmdlMetadataDoc);
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string nameVal = cmdlMetadataDoc->getName();
		CAF_CM_VALIDATE_STRING(nameVal);
		thisXml->addAttribute("name", nameVal);

		const std::string valueVal =
			cmdlMetadataDoc->getValue();
		CAF_CM_VALIDATE_STRING(valueVal);

		const SmartPtrCXmlElement valueXml =
			thisXml->createAndAddElement("value");
		valueXml->setValue(valueVal);
	}
	CAF_CM_EXIT;
}

SmartPtrCCmdlMetadataDoc CmdlMetadataXml::parse(
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("CmdlMetadataXml", "parse");

	SmartPtrCCmdlMetadataDoc cmdlMetadataDoc;

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string nameStrVal =
			thisXml->findRequiredAttribute("name");
		const std::string nameVal = nameStrVal;

		const SmartPtrCXmlElement valueXml =
			thisXml->findRequiredChild("value");

		std::string valueVal;
		if (! valueXml.IsNull()) {
			valueVal = valueXml->getValue();
		}

		cmdlMetadataDoc.CreateInstance();
		cmdlMetadataDoc->initialize(
			nameVal,
			valueVal);
	}
	CAF_CM_EXIT;

	return cmdlMetadataDoc;
}

