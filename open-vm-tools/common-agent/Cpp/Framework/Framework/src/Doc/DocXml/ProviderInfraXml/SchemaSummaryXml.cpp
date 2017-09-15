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

#include "Doc/DocXml/ProviderInfraXml/ClassCollectionXml.h"

#include "Doc/ProviderInfraDoc/CClassCollectionDoc.h"
#include "Doc/ProviderInfraDoc/CSchemaSummaryDoc.h"
#include "Xml/XmlUtils/CXmlElement.h"
#include "Doc/DocXml/ProviderInfraXml/SchemaSummaryXml.h"

using namespace Caf;

void SchemaSummaryXml::add(
	const SmartPtrCSchemaSummaryDoc schemaSummaryDoc,
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("SchemaSummaryXml", "add");

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(schemaSummaryDoc);
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string providerNamespaceVal = schemaSummaryDoc->getProviderNamespace();
		CAF_CM_VALIDATE_STRING(providerNamespaceVal);
		thisXml->addAttribute("providerNamespace", providerNamespaceVal);

		const std::string providerNameVal = schemaSummaryDoc->getProviderName();
		CAF_CM_VALIDATE_STRING(providerNameVal);
		thisXml->addAttribute("providerName", providerNameVal);

		const std::string providerVersionVal = schemaSummaryDoc->getProviderVersion();
		CAF_CM_VALIDATE_STRING(providerVersionVal);
		thisXml->addAttribute("providerVersion", providerVersionVal);

		const SmartPtrCClassCollectionDoc classCollectionVal =
			schemaSummaryDoc->getClassCollection();
		CAF_CM_VALIDATE_SMARTPTR(classCollectionVal);

		const SmartPtrCXmlElement classCollectionXml =
			thisXml->createAndAddElement("classCollection");
		ClassCollectionXml::add(classCollectionVal, classCollectionXml);

		const std::string invokerPathVal = schemaSummaryDoc->getInvokerPath();
		if (! invokerPathVal.empty()) {
			thisXml->addAttribute("invokerPath", invokerPathVal);
		}
	}
	CAF_CM_EXIT;
}

SmartPtrCSchemaSummaryDoc SchemaSummaryXml::parse(
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("SchemaSummaryXml", "parse");

	SmartPtrCSchemaSummaryDoc schemaSummaryDoc;

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string providerNamespaceStrVal =
			thisXml->findRequiredAttribute("providerNamespace");
		const std::string providerNamespaceVal = providerNamespaceStrVal;

		const std::string providerNameStrVal =
			thisXml->findRequiredAttribute("providerName");
		const std::string providerNameVal = providerNameStrVal;

		const std::string providerVersionStrVal =
			thisXml->findRequiredAttribute("providerVersion");
		const std::string providerVersionVal = providerVersionStrVal;

		const SmartPtrCXmlElement classCollectionXml =
			thisXml->findRequiredChild("classCollection");

		SmartPtrCClassCollectionDoc classCollectionVal;
		if (! classCollectionXml.IsNull()) {
			classCollectionVal = ClassCollectionXml::parse(classCollectionXml);
		}

		const std::string invokerPathStrVal =
			thisXml->findOptionalAttribute("invokerPath");
		const std::string invokerPathVal = invokerPathStrVal;

		schemaSummaryDoc.CreateInstance();
		schemaSummaryDoc->initialize(
			providerNamespaceVal,
			providerNameVal,
			providerVersionVal,
			classCollectionVal,
			invokerPathVal);
	}
	CAF_CM_EXIT;

	return schemaSummaryDoc;
}

