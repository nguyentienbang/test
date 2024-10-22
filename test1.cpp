#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Khai báo biến
    int n;
    cout << "Nhap so luong nam muon quan ly: ";
    cin >> n;

    map<int, int> year_birth_count;
    
    // Nhập dữ liệu
    for (int i = 0; i < n; ++i) {
        int year, births;
        cout << "Nhap nam va so luong nguoi sinh ra trong nam do (nam so_luong): ";
        cin >> year >> births;
        year_birth_count[year] = births;
    }

    // Tìm số năm có cùng số lượng người sinh ra
    map<int, int> birth_frequency;
    for (const auto& entry : year_birth_count) {
        birth_frequency[entry.second]++;
    }

    // Hiển thị số lượng năm có cùng số người sinh ra
    cout << "\nSo nam co cung so luong nguoi sinh ra:\n";
    for (const auto& entry : birth_frequency) {
        cout << entry.second << " nam co " << entry.first << " nguoi sinh ra\n";
    }

    // Tìm số lượng người sinh ra lớn nhất và nhỏ nhất
    auto max_births = max_element(year_birth_count.begin(), year_birth_count.end(),
                                  [](const pair<int, int>& a, const pair<int, int>& b) {
                                      return a.second < b.second;
                                  });

    auto min_births = min_element(year_birth_count.begin(), year_birth_count.end(),
                                  [](const pair<int, int>& a, const pair<int, int>& b) {
                                      return a.second < b.second;
                                  });

    // In ra các năm có số lượng người sinh ra lớn nhất và nhỏ nhất
    cout << "\nNam co so luong nguoi sinh ra lon nhat: " << max_births->first 
         << " voi " << max_births->second << " nguoi.\n";

    cout << "Nam co so luong nguoi sinh ra nho nhat: " << min_births->first 
         << " voi " << min_births->second << " nguoi.\n";

    return 0;
}
