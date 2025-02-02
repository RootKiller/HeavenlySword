/* 
 * 
 * Confidential Information of Telekinesys Research Limited (t/a Havok).  Not for disclosure or distribution without Havok's
 * prior written consent.This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Level 2 and Level 3 source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2006 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 * 
 */

#ifndef HK_COLLIDE2_MULTI_RAY_SHAPE_H
#define HK_COLLIDE2_MULTI_RAY_SHAPE_H

#include <hkcollide/shape/convex/hkConvexShape.h>

extern const hkClass hkMultiRayShapeClass;

	/// A shape that allows you to cast multiple rays.
	/// If you use this shape as a normal shape as part of a hkRigidBody, this
	/// shape will generate it's contact points using a rayCast.
	/// As a result, the rays are treated like solid objects.
class hkMultiRayShape : public hkShape
{
	public:

		HK_DECLARE_REFLECTION();

		///A ray from m_start to m_end.
		struct Ray
		{
			HK_DECLARE_REFLECTION();

			hkVector4 m_start;
			hkVector4 m_end;
		};

	public:
		
			/// Creates a new hkMultiRayShape with the specified rays and a rayPenetrationDistance (See hkMultiRayShapeCinfo for more details).
		hkMultiRayShape( const Ray* rays, int nRays, hkReal rayPenetrationDistance = 0.0f );

			// hkShape implementation.
 		void getAabb( const hkTransform& localToWorld, hkReal tolerance, hkAabb& out  ) const;

			///Gets this hkShape's secondary type. For hkMultiRayShapes, this is HK_SHAPE_MULTI_RAY.
		virtual hkShapeType getType() const { return HK_SHAPE_MULTI_RAY; }

		virtual void calcStatistics( hkStatisticsCollector* collector) const;

			/// Returns the shape's rays extended by the shapes tolerance.
		inline const hkArray<Ray>& getRays() const{ return m_rays; }

			/// Returns the shape's ray penetration distance i.e. the distance each ray will be extended by and the distance that the physics system will allow each ray penetrate objects by. This helps to reduce jitter.
		inline hkReal getRayPenetrationDistance() const{ return m_rayPenetrationDistance; }

			/// Finds the closest intersection between the shape and a ray defined in the shape's local space, starting at fromLocal, ending at toLocal.
		virtual hkBool castRay( const hkShapeRayCastInput& input, hkShapeRayCastOutput& results ) const;

			/// a callback driven raycast
		virtual void castRayWithCollector( const hkShapeRayCastInput& input, const hkCdBody& cdBody, hkRayHitCollector& collector ) const;
		

	protected:
			// The rays defined in local space
		hkArray<struct Ray> m_rays;

                        // The ray penetration distance
		hkReal m_rayPenetrationDistance;


	public:

		hkMultiRayShape( hkFinishLoadedObjectFlag flag ) : hkShape(flag), m_rays(flag) {}

};


#endif // HK_COLLIDE2_LINE_SEGMENT_SHAPE_H

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
