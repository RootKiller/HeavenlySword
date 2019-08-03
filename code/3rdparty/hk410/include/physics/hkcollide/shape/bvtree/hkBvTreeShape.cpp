/* 
 * 
 * Confidential Information of Telekinesys Research Limited (t/a Havok).  Not for disclosure or distribution without Havok's
 * prior written consent.This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Level 2 and Level 3 source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2006 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 * 
 */

#include <hkcollide/hkCollide.h>
#include <hkcollide/shape/bvtree/hkBvTreeShape.h>
#include <hkbase/class/hkTypeInfo.h>

hkShapeType hkBvTreeShape::getType() const { return HK_SHAPE_BV_TREE; }

void hkBvTreeShape::calcStatistics( hkStatisticsCollector* collector ) const
{
	collector->beginObject("BvTreeShape", collector->MEMORY_SHARED, this);
	collector->addChildObject("Collection", collector->MEMORY_SHARED, getShapeCollection() );
	collector->endObject();
}

const hkShapeContainer* hkBvTreeShape::getContainer() const
{
	return &m_child;
}

/*
* Havok SDK - CLIENT RELEASE, BUILD(#20060902)
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