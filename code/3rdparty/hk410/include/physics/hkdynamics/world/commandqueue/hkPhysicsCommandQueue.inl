/* 
 * 
 * Confidential Information of Telekinesys Research Limited (t/a Havok).  Not for disclosure or distribution without Havok's
 * prior written consent.This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Level 2 and Level 3 source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2006 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 * 
 */

hkPhysicsCommandQueue::hkPhysicsCommandQueue( hkPhysicsCommand* bufferStart, hkPhysicsCommand* bufferEnd )
{
	m_start   = bufferStart;
	m_current = bufferStart;
	m_end     = bufferEnd;
}

template<typename COMMAND_STRUCT> 
void hkPhysicsCommandQueue::addCommand(COMMAND_STRUCT command)
{
	COMMAND_STRUCT& dest = static_cast<COMMAND_STRUCT&>(*m_current);
	dest = command;
	int size = HK_NEXT_MULTIPLE_OF(16, sizeof(COMMAND_STRUCT) );
	m_current = hkAddByteOffset(m_current, size);
	HK_ASSERT2( 0xf03234f5, m_current <= m_end, "Running out of command buffer" );
}


template<typename COMMAND_STRUCT> 
COMMAND_STRUCT& hkPhysicsCommandQueue::newCommand()
{
	COMMAND_STRUCT* res = new (m_current)COMMAND_STRUCT();
	int size = HK_NEXT_MULTIPLE_OF(16, sizeof(COMMAND_STRUCT) );
	m_current = hkAddByteOffset(m_current, size);
	HK_ASSERT2( 0xf03234f5, m_current <= m_end, "Running out of command buffer" );
	return *res;
}



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
