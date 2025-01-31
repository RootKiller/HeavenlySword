/* 
 * 
 * Confidential Information of Telekinesys Research Limited (t/a Havok).  Not for disclosure or distribution without Havok's
 * prior written consent.This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Level 2 and Level 3 source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2006 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 * 
 */

#include <hkutilities/collide/hkShapeGenerator.h>
#include <hkinternal/preprocess/convexhull/hkGeometryUtility.h>

#include <hkcollide/shape/box/hkBoxShape.h>
#include <hkcollide/shape/sphere/hkSphereShape.h>
#include <hkcollide/shape/convexvertices/hkConvexVerticesShape.h>
#include <hkcollide/shape/triangle/hkTriangleShape.h>
#include <hkcollide/shape/capsule/hkCapsuleShape.h>

#include <hkmath/util/hkPseudoRandomGenerator.h>


hkConvexVerticesShape* HK_CALL hkShapeGenerator::createRandomConvexVerticesShape(	const hkVector4& minbox,
																					const hkVector4& maxbox,
																					int numvert, 
																					hkPseudoRandomGenerator *generator, 
																					Flags flags )
{
	HK_ASSERT(0x4028019b,  (minbox.compareLessThanEqual4(maxbox) & HK_VECTOR3_COMPARE_MASK_XYZ) == HK_VECTOR3_COMPARE_MASK_XYZ );
	hkArray<hkVector4> verts(numvert);
	for(int i = 0; i < numvert; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			verts[i](j) = generator->getRandRange( minbox(j), maxbox(j) );
		}
	}

	hkStridedVertices stridedVerts;
	{
		stridedVerts.m_numVertices = numvert;
		stridedVerts.m_striding = sizeof(hkVector4);
		stridedVerts.m_vertices = &(verts[0](0));
	}


	if ( flags == NO_PLANE_EQUATIONS )
	{
		hkArray<hkVector4> dummyPlaneEquations;

		return new hkConvexVerticesShape( stridedVerts, dummyPlaneEquations);
	}

	hkArray<hkVector4> planeEquations;
	hkGeometry geom;
	// Usually plane equations should be precomputed off line. We disable the performance warning
	hkBool wasEnabled = hkError::getInstance().isEnabled(0x34df5494);
	hkError::getInstance().setEnabled(0x34df5494, false); //hkGeometryUtility.cpp:26
	hkGeometryUtility::createConvexGeometry( stridedVerts, geom, planeEquations );
	hkError::getInstance().setEnabled(0x34df5494, wasEnabled); //hkGeometryUtility.cpp:26

	stridedVerts.m_vertices = &(geom.m_vertices[0](0));
	stridedVerts.m_numVertices = geom.m_vertices.getSize();
	return new hkConvexVerticesShape( stridedVerts, planeEquations);
}


hkConvexVerticesShape* HK_CALL hkShapeGenerator::createRandomConvexVerticesShapeWithThinTriangles(	const hkVector4& minbox,
																									const hkVector4& maxbox,
																									int numvert, 
																									float minEdgeLen, 
																									hkPseudoRandomGenerator *generator, 
																									Flags flags )
{
	HK_ASSERT(0x79af13e8,  (minbox.compareLessThanEqual4(maxbox) & HK_VECTOR3_COMPARE_MASK_XYZ) == HK_VECTOR3_COMPARE_MASK_XYZ );
	hkInplaceArrayAligned16<hkVector4,48> verts(numvert+1);
	for(int i = 0; i < numvert; ++i)
	{
		{
			for(int j = 0; j < 3; ++j)
			{
				verts[i](j) = generator->getRandRange( minbox(j), maxbox(j) );
			}
		}
		{
			for(int j = 0; j < 3; ++j)
			{
				verts[i+1](j) = verts[i](j) + generator->getRandRange( -minEdgeLen, minEdgeLen );
			}
		}
		i++;
	}

	hkStridedVertices stridedVerts;
	{
		stridedVerts.m_numVertices = numvert;
		stridedVerts.m_striding = sizeof(hkVector4);
		stridedVerts.m_vertices = &(verts[0](0));
	}


	if ( flags == NO_PLANE_EQUATIONS )
	{
		hkArray<hkVector4> dummyPlaneEquations;
		return new hkConvexVerticesShape( stridedVerts, dummyPlaneEquations);
	}

	hkArray<hkVector4> planeEquations;
	hkGeometry geom;
	// Usually plane equations should be precomputed off line. We disable the performance warning
	hkBool wasEnabled = hkError::getInstance().isEnabled(0x34df5494);
	hkError::getInstance().setEnabled(0x34df5494, false); //hkGeometryUtility.cpp:26
	hkGeometryUtility::createConvexGeometry( stridedVerts, geom, planeEquations );
	hkError::getInstance().setEnabled(0x34df5494, wasEnabled); //hkGeometryUtility.cpp:26

	stridedVerts.m_vertices = &(geom.m_vertices[0](0));
	stridedVerts.m_numVertices = geom.m_vertices.getSize();
	return new hkConvexVerticesShape( stridedVerts, planeEquations);
}

static HK_ALIGN16( const float vertexSignArray[8][4] ) = {
	{ 1.0f, 1.0f, 1.0f, 0.0f },	// zyx = 000
	{-1.0f, 1.0f, 1.0f, 0.0f },	// zyx = 001  
	{ 1.0f,-1.0f, 1.0f, 0.0f },	// zyx = 010
	{-1.0f,-1.0f, 1.0f, 0.0f },	// zyx = 011
	{ 1.0f, 1.0f,-1.0f, 0.0f },	// zyx = 100
	{-1.0f, 1.0f,-1.0f, 0.0f }, // zyx = 101
	{ 1.0f,-1.0f,-1.0f, 0.0f }, // zyx = 110
	{-1.0f,-1.0f,-1.0f, 0.0f }	// zyx = 111
};

hkConvexShape* HK_CALL hkShapeGenerator::createConvexShape( const hkVector4& extents, ShapeType type, hkPseudoRandomGenerator *generator )
{
	if ( type == RANDOM )
	{
		type = ShapeType( int(generator->getRandRange( RANDOM+1, SHAPE_MAX ) ) );
	}

	switch(type)
	{
	case	BOX:
		{
			hkConvexShape* box =  new hkBoxShape( extents );
			box->setRadius(0.f);
			return box;
		}
	case	SPHERE:
		{
			const hkReal minLen = hkMath::min2( extents(0), hkMath::min2(extents(1), extents(2) ) );
			return new hkSphereShape( minLen );
		}

	case CAPSULE:
		{
			hkReal radius = hkMath::min2( extents(0), hkMath::min2( extents(1), extents(2) ) );
			radius *= 0.5f;
			hkVector4 A; A.set( extents(0) - radius, extents(1) - radius, extents(2) - radius );
			hkVector4 B; B.setNeg4(A);
			return new hkCapsuleShape( A,B,radius );
		}

	case	TRIANGLE:
		{
			int i;
			if ( extents(0) > extents(1) )
			{
				i = 0;
			}
			else
			{
				i = 1;
			}
			hkTriangleShape* shape = new hkTriangleShape();
			shape->getVertex(0) = extents;
			shape->getVertex(1).setNeg4( extents );
			shape->getVertex(2) = extents;
			shape->getVertex(2)(i) *= -1;
			return shape;
		}

		/*
	case THIN_TRIANGLE:
		{
			int i;
			if ( extents(0) > extents(1) )
			{
				i = 0;
			}
			else
			{
				i = 1;
			}
			hkTriangleShape* shape = new hkTriangleShape();
			shape->getVertex(0) = extents;
			shape->getVertex(1).setNeg4( extents );
			shape->getVertex(2) = extents;
			shape->getVertex(2)(i) *= 0.99f;
			return shape;
		}
		*/

	case	CONVEX_VERTICES:
		{
			hkVector4 negExtents; negExtents.setNeg4( extents );
			return createRandomConvexVerticesShape( negExtents, extents, 30, generator, NONE );
		}
	case	CONVEX_VERTICES_BOX:
		{
		hkArray<hkVector4> planeEquations;
		hkGeometry geom;

		hkStridedVertices stridedVerts;
		{
			stridedVerts.m_numVertices = 8;
			stridedVerts.m_striding = sizeof(hkVector4);
			stridedVerts.m_vertices = &vertexSignArray[0][0];
		}
		// Usually plane equations should be precomputed off line. We disable the performance warning
		hkBool wasEnabled = hkError::getInstance().isEnabled(0x34df5494);
		hkError::getInstance().setEnabled(0x34df5494, false); //hkGeometryUtility.cpp:26
		hkGeometryUtility::createConvexGeometry( stridedVerts, geom, planeEquations );
		hkError::getInstance().setEnabled(0x34df5494, wasEnabled); //hkGeometryUtility.cpp:26

		stridedVerts.m_vertices = &(geom.m_vertices[0](0));
		stridedVerts.m_numVertices = geom.m_vertices.getSize();

		return new hkConvexVerticesShape( stridedVerts, planeEquations);
		}

	default:
		HK_ASSERT2(0x76e86a15,  0, "unknown shape type" );
		return HK_NULL;
	}
}

const char* HK_CALL hkShapeGenerator::getShapeTypeName( ShapeType type )
{
	switch(type)
	{
	case	BOX: return "BOX";
	case SPHERE: return "SPHERE";
	case CAPSULE: return "CAPSULE";
	case TRIANGLE: return "TRIANGLE";
	//case THIN_TRIANGLE: return "THIN_TRIANGLE";
	case CONVEX_VERTICES: return "CONVEX_VERTICES";
	case CONVEX_VERTICES_BOX: return "CONVEX_VERTICES_BOX";
	default: return "Unknown";
	}
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
