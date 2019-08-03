/* 
 * 
 * Confidential Information of Telekinesys Research Limited (t/a Havok).  Not for disclosure or distribution without Havok's
 * prior written consent.This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Level 2 and Level 3 source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2006 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 * 
 */

#ifndef HK_DYNAMICS2_GENERIC_CONSTRAINT_PARAMETERS_H
#define HK_DYNAMICS2_GENERIC_CONSTRAINT_PARAMETERS_H


class hkGenericConstraintDataParameters
{
public:

	hkVector4 m_pivotAw;
	hkVector4 m_pivotBw;

	hkRotation m_linearBasisW;
	hkRotation m_angularBasisAw;
	hkRotation m_angularBasisBw;

	const hkTransform* m_rbA;
	const hkTransform* m_rbB;

	int m_currentResult;
};

#endif

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