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

#include "Doc/CafCoreTypesDoc/CPropertyCollectionDoc.h"
#include "Doc/CafCoreTypesDoc/CStatisticsDoc.h"
#include "Xml/XmlUtils/CXmlElement.h"
#include "Doc/DocXml/CafCoreTypesXml/StatisticsXml.h"
#include "Doc/DocXml/CafCoreTypesXml/PropertyCollectionXml.h"

using namespace Caf;

void StatisticsXml::add(
	const SmartPtrCStatisticsDoc statisticsDoc,
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("StatisticsXml", "add");

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(statisticsDoc);
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const SmartPtrCPropertyCollectionDoc propertyCollectionVal =
			statisticsDoc->getPropertyCollection();
		CAF_CM_VALIDATE_SMARTPTR(propertyCollectionVal);

		const SmartPtrCXmlElement propertyCollectionXml =
			thisXml->createAndAddElement("propertyCollection");
		PropertyCollectionXml::add(propertyCollectionVal, propertyCollectionXml);

		const std::string providerJobNumVal =
			CStringConv::toString<int32>(statisticsDoc->getProviderJobNum());
		if (! providerJobNumVal.empty()) {
			thisXml->addAttribute("providerJobNum", providerJobNumVal);
		}

		const std::string providerJobTotalVal =
			CStringConv::toString<int32>(statisticsDoc->getProviderJobTotal());
		if (! providerJobTotalVal.empty()) {
			thisXml->addAttribute("providerJobTotal", providerJobTotalVal);
		}

		const std::string providerJobDurationSecsVal =
			CStringConv::toString<int32>(statisticsDoc->getProviderJobDurationSecs());
		if (! providerJobDurationSecsVal.empty()) {
			thisXml->addAttribute("providerJobDurationSecs", providerJobDurationSecsVal);
		}

		const std::string pmeNumVal =
			CStringConv::toString<int32>(statisticsDoc->getPmeNum());
		if (! pmeNumVal.empty()) {
			thisXml->addAttribute("pmeNum", pmeNumVal);
		}

		const std::string pmeTotalVal =
			CStringConv::toString<int32>(statisticsDoc->getPmeTotal());
		if (! pmeTotalVal.empty()) {
			thisXml->addAttribute("pmeTotal", pmeTotalVal);
		}

		const std::string pmeDurationSecsVal =
			CStringConv::toString<int32>(statisticsDoc->getPmeDurationSecs());
		if (! pmeDurationSecsVal.empty()) {
			thisXml->addAttribute("pmeDurationSecs", pmeDurationSecsVal);
		}
	}
	CAF_CM_EXIT;
}

SmartPtrCStatisticsDoc StatisticsXml::parse(
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("StatisticsXml", "parse");

	SmartPtrCStatisticsDoc statisticsDoc;

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const SmartPtrCXmlElement propertyCollectionXml =
			thisXml->findRequiredChild("propertyCollection");

		SmartPtrCPropertyCollectionDoc propertyCollectionVal;
		if (! propertyCollectionXml.IsNull()) {
			propertyCollectionVal = PropertyCollectionXml::parse(propertyCollectionXml);
		}

		const std::string providerJobNumStrVal =
			thisXml->findOptionalAttribute("providerJobNum");
		int32 providerJobNumVal = 0;
		if (! providerJobNumStrVal.empty()) {
			providerJobNumVal = CStringConv::fromString<int32>(providerJobNumStrVal);
		}

		const std::string providerJobTotalStrVal =
			thisXml->findOptionalAttribute("providerJobTotal");
		int32 providerJobTotalVal = 0;
		if (! providerJobTotalStrVal.empty()) {
			providerJobTotalVal = CStringConv::fromString<int32>(providerJobTotalStrVal);
		}

		const std::string providerJobDurationSecsStrVal =
			thisXml->findOptionalAttribute("providerJobDurationSecs");
		int32 providerJobDurationSecsVal = 0;
		if (! providerJobDurationSecsStrVal.empty()) {
			providerJobDurationSecsVal = CStringConv::fromString<int32>(providerJobDurationSecsStrVal);
		}

		const std::string pmeNumStrVal =
			thisXml->findOptionalAttribute("pmeNum");
		int32 pmeNumVal = 0;
		if (! pmeNumStrVal.empty()) {
			pmeNumVal = CStringConv::fromString<int32>(pmeNumStrVal);
		}

		const std::string pmeTotalStrVal =
			thisXml->findOptionalAttribute("pmeTotal");
		int32 pmeTotalVal = 0;
		if (! pmeTotalStrVal.empty()) {
			pmeTotalVal = CStringConv::fromString<int32>(pmeTotalStrVal);
		}

		const std::string pmeDurationSecsStrVal =
			thisXml->findOptionalAttribute("pmeDurationSecs");
		int32 pmeDurationSecsVal = 0;
		if (! pmeDurationSecsStrVal.empty()) {
			pmeDurationSecsVal = CStringConv::fromString<int32>(pmeDurationSecsStrVal);
		}

		statisticsDoc.CreateInstance();
		statisticsDoc->initialize(
			propertyCollectionVal,
			providerJobNumVal,
			providerJobTotalVal,
			providerJobDurationSecsVal,
			pmeNumVal,
			pmeTotalVal,
			pmeDurationSecsVal);
	}
	CAF_CM_EXIT;

	return statisticsDoc;
}

