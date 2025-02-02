/* 
 * 
 * Confidential Information of Telekinesys Research Limited (t/a Havok).  Not for disclosure or distribution without Havok's
 * prior written consent.This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Level 2 and Level 3 source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2006 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 * 
 */

// WARNING: THIS FILE IS GENERATED. EDITS WILL BE LOST.
// Generated from 'hkutilities/collide/filter/constrainedsystem/hkConstrainedSystemFilter.h'

#include <hkbase/hkBase.h>
#include <hkbase/class/hkClass.h>
#include <hkbase/class/hkInternalClassMember.h>
#include <hkutilities/collide/filter/constrainedsystem/hkConstrainedSystemFilter.h>


// External pointer and enum types
extern const hkClass hkCollisionFilterClass;

//
// Class hkConstrainedSystemFilter
//
const hkInternalClassMember hkConstrainedSystemFilter::Members[] =
{
	{ "otherFilter", &hkCollisionFilterClass, HK_NULL, hkClassMember::TYPE_POINTER, hkClassMember::TYPE_STRUCT, 0, 0, HK_OFFSET_OF(hkConstrainedSystemFilter,m_otherFilter) }
};

extern const hkClass hkConstrainedSystemFilterClass;
const hkClass hkConstrainedSystemFilterClass(
	"hkConstrainedSystemFilter",
	&hkCollisionFilterClass, // parent
	sizeof(hkConstrainedSystemFilter),
	HK_NULL,
	1, // interfaces
	HK_NULL,
	0, // enums
	reinterpret_cast<const hkClassMember*>(hkConstrainedSystemFilter::Members),
	int(sizeof(hkConstrainedSystemFilter::Members)/sizeof(hkInternalClassMember)),
	HK_NULL // defaults
	);

/*
* Havok SDK - PUBLIC RELEASE, BUILD(#20060902)
*
* Confidential Information of Havok.  (C) Copyright 1999-2006 
* Telekinesys Research Limited t/a Havok. All Rights Reserved. The Havok
* Logo, and the Havok buzzsaw logo are trademarks of Havok.  Title, ownership
* rights, and intellectual property rights in the Havok software remain in
* Havok and/or its suppliers.
*
* Use of this software for evaluation purposes is subject to and indicates 
* acceptance of the End User licence Agreement for this product. A copy of 
* the license is included with this software and is also available from salesteam@havok.com.
*
*/
