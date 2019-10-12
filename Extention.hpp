#include <random>

namespace ext
{
	/** Функци GetRandomValueслучайно значение типа int из указанного интервала.
	*
	* @param min нижняя граница интервала (включительно)
	* @param max верхняя граница интервала (включительно)
	* @param isDebugMode если true то каждый раз будет генерироваться одинакова последовальность для удобства при отладке
	* @return случайное значение типа int из указанно о интервала
	*/
	int GetRandomValue(int min, int max, bool isDebugMode = false)
	{
		static auto randomEngine = [isDebugMode]() { return isDebugMode ? std::mt19937{} : std::mt19937(std::random_device{}()); }();
		auto distribution = std::uniform_int_distribution<int>(min, max);
		return distribution(randomEngine);
	}
}
