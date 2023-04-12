#ifndef GAME_MATH
#define GAME_MATH
#include "Vector3.h"
#define PI 3.14159
#include <vector>
using namespace std;
namespace Math{

	Vector3 RotatePoint(Vector3 point, Vector3 pivot, float rot);

	double ConvertToRadians(double degrees);
	double ConvertToDegrees(double radians);

	float Min(vector<float> x);
	float Max(vector<float> x);

	float Abs(float x);
}

#endif
