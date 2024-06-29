#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;

    void recur(vector<int>& tmpRes, vector<int>& candidates, int target, int start) {
        if (target == 0) {
            result.push_back(tmpRes);
            return;
        }

        for (int i = start; i < candidates.size() && candidates[i] <= target; i++) {
            tmpRes.push_back(candidates[i]);
            recur(tmpRes, candidates, target - candidates[i], i); // передаём i для возможности использования элементов больше одного раза
            tmpRes.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Сортируем, чтобы использовать элементы в порядке возрастания

        auto max_it = max_element(candidates.begin(), candidates.end());
        int max_value = *max_it; // Разыменование итератора для получения значения
       
        //Удаляем эдементы больше таргета
        if (max_value > target)
        {
            for (int j = target + 1; j <= max_value; j++)
            {
                auto it = find(candidates.begin(), candidates.end(), j);
                if (it != candidates.end()) candidates.erase(it);
            }
        }

        vector<int> tmpRes;
        recur(tmpRes, candidates, target, 0);

        // Используем set для удаления дубликатов

        /*set в C++ хранит элементы в отсортированном порядке и автоматически удаляет дубликаты при добавлении новых элементов.
        Однако он проверяет наличие дубликатов с помощью оператора сравнения или компаратора,
        который определён для типа элементов, хранящихся в set.
        В нашем случае, элементами std::set являются векторы std::vector<int>.
        При добавлении нового вектора в set, set использует оператор сравнения или компаратор,
        который сравнивает элементы векторов. По умолчанию std::vector<int> сравнивается лексикографически (поэлементно).
        Таким образом, std::set не удаляет дубликаты "автоматически" в смысле,
        что он самостоятельно находит и удаляет повторяющиеся векторы.
        Он использует свой механизм проверки на уникальность элементов при их добавлении.
        Если новый элемент (вектор) уже присутствует в set, он не добавляется повторно.*/

        set<vector<int>> unique_vectors(result.begin(), result.end());
        result.assign(unique_vectors.begin(), unique_vectors.end());

        return result;
    }
};

int main() {
    Solution s;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = s.combinationSum(candidates, target);

    for (const auto& au : result) {
        for (int it : au) {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}
// 2 3 6 7  7
// 
// 2 2 t
// 2 3 t
// 2 6 t
// 2 7 f

// 2 2 2 t
// 2 2 3 T
// 2 2 6 f
// 2 2 7 f

// 2 2 2 2 f
// 2 2 2 3 f
// 2 2 2 6 f
// 2 2 2 7 f