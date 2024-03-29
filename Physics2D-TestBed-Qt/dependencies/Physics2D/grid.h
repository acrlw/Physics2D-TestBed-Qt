#ifndef PHYSICS_BROADPHASE_GRID_H
#define PHYSICS_BROADPHASE_GRID_H
#include "aabb.h"
#include "body.h"
#include "list"
#include "vector"
namespace Physics2D
{
	//TODO 20220704
	//1. Incremental Update Bodies, calculating the different between two cellList
	//2. Position combine to u64 and split into two u32
	//3. Raycast query bodies
	class UniformGrid
	{
	public:
		UniformGrid(const real& width = 100.0f, const real& height = 100.0f, const uint32_t rows = 200, const uint32_t columns = 200);
		Container::Vector<std::pair<Body*, Body*>> generate();
		Container::Vector<Body*> raycast(const Vector2& p, const Vector2& d);

		void updateAll();
		void update(Body* body);
		void insert(Body* body);
		void remove(Body* body);

		int rows()const;
		void setRows(const int& size);

		int columns()const;
		void setColumns(const int& size);

		real width()const;
		void setWidth(const real& size);

		real height()const;
		void setHeight(const real& size);

		struct Position
		{
			Position() = default;
			Position(const uint32_t& _x, const uint32_t& _y): x(_x), y(_y){}
			uint32_t x = 0;
			uint32_t y = 0;
			bool operator<(const Position& rhs)const
			{
				if (x < rhs.x)
					return true;
				if (x == rhs.x)
					return y < rhs.y;
				return false;
			}
			bool operator>(const Position& rhs)const
			{
				if (x > rhs.x)
					return true;
				if (x == rhs.x)
					return y > rhs.y;
				return false;
			}
			bool operator==(const Position& rhs)const
			{
				return x == rhs.x && y == rhs.y;
			}
		};
		//AABB query cells
		Container::Vector<Position> queryCells(const AABB& aabb);

		//ray cast query cells
		Container::Vector<Position> queryCells(const Vector2& start, const Vector2& direction);
		real cellHeight()const;
		real cellWidth()const;

		Container::Map<Position, Container::Vector<Body*>> m_cellsToBodies;
		Container::Map<Body*, Container::Vector<Position>> m_bodiesToCells;

		void fullUpdate(Body* body);
		void incrementalUpdate(Body* body);
	private:
		enum class Operation {
			Add,
			Delete
		};
		void updateGrid();
		void changeGridSize();
		void updateBodies();
		Container::Vector<std::pair<UniformGrid::Operation, UniformGrid::Position>> compareCellList(const Container::Vector<Position>& oldCellList, const Container::Vector<Position>& newCellList);
		real m_width;
		real m_height;
		uint32_t m_rows;
		uint32_t m_columns;


		real m_cellWidth = 0.0f;
		real m_cellHeight = 0.0f;
	};
}

#endif // !PHYSICS_BROADPHASE_GRID_H
