/* 
 * 
 * Confidential Information of Telekinesys Research Limited (t/a Havok).  Not for disclosure or distribution without Havok's
 * prior written consent.This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Level 2 and Level 3 source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2006 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 * 
 */

// WARNING: THIS FILE IS GENERATED. EDITS WILL BE LOST.
// Generated from 'hkdynamics/constraint/constraintkit/hkGenericConstraintData.h'

#include <hkdynamics/hkDynamics.h>
#include <hkbase/class/hkClass.h>
#include <hkbase/class/hkInternalClassMember.h>
#include <hkdynamics/constraint/constraintkit/hkGenericConstraintData.h>


// External pointer and enum types
extern const hkClass hkBridgeAtomsClass;
extern const hkClass hkGenericConstraintDataSchemeClass;

//
// Class hkGenericConstraintData
//
const hkInternalClassMember hkGenericConstraintData::Members[] =
{
	{ "atoms", &hkBridgeAtomsClass, HK_NULL, hkClassMember::TYPE_STRUCT, hkClassMember::TYPE_VOID, 0, 0, HK_OFFSET_OF(hkGenericConstraintData,m_atoms) },
	{ "scheme", &hkGenericConstraintDataSchemeClass, HK_NULL, hkClassMember::TYPE_STRUCT, hkClassMember::TYPE_VOID, 0, 0, HK_OFFSET_OF(hkGenericConstraintData,m_scheme) }
};
extern const hkClass hkConstraintDataClass;

extern const hkClass hkGenericConstraintDataClass;
const hkClass hkGenericConstraintDataClass(
	"hkGenericConstraintData",
	&hkConstraintDataClass, // parent
	sizeof(hkGenericConstraintData),
	HK_NULL,
	0, // interfaces
	HK_NULL,
	0, // enums
	reinterpret_cast<const hkClassMember*>(hkGenericConstraintData::Members),
	int(sizeof(hkGenericConstraintData::Members)/sizeof(hkInternalClassMember)),
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
