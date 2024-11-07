#include "triangleArray.cpp"

using namespace std;

int main() {
    TriangleArray triangleArray("triangles.txt");

    cout << triangleArray.GetCount() << '\n';

    for (int i = 0; i < triangleArray.GetCount(); ++i) {
        Triangle* triangle = triangleArray.GetMember(i);
        if (triangle != nullptr) {
            triangle->Output();
        }
    }

    int invalidCount;
    triangleArray.RemoveInvalidTriangles(invalidCount);
    cout << invalidCount << '\n';
    cout << triangleArray.GetCount() << '\n';

    cout << "Equilateral: " << triangleArray.ClassifyTriangles("Equilateral") << '\n';
    cout << "Isosceles: " << triangleArray.ClassifyTriangles("Isosceles") << '\n';
    cout << "Scalene: " << triangleArray.ClassifyTriangles("Scalene") << '\n';

    return 0;
}