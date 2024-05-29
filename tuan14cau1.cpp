#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Vector {
public:
    Vector() {
        arr = new T[1];
        dungLuong = 1;
        soLuongHienTai = 0;
    }

    ~Vector() {
        delete[] arr;
    }

    void them(T duLieu) {
        if (soLuongHienTai == dungLuong) {
            T* tam = new T[2 * dungLuong];
            for (int i = 0; i < dungLuong; i++) {
                tam[i] = arr[i];
            }
            delete[] arr;
            dungLuong *= 2;
            arr = tam;
        }
        arr[soLuongHienTai] = duLieu;
        soLuongHienTai++;
    }

    T lay(int chiSo) const {
        if (chiSo < soLuongHienTai)
            return arr[chiSo];
        throw out_of_range("Chi so vuot qua pham vi");
    }

    void xoa() {
        soLuongHienTai--;
    }

    int kichThuoc() const {
        return soLuongHienTai;
    }

    int layDungLuong() const {
        return dungLuong;
    }

    void in() const {
        for (int i = 0; i < soLuongHienTai; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

private:
    T* arr;
    int dungLuong;
    int soLuongHienTai;
};

int main() {
    Vector<int> v;
    v.them(10);
    v.them(20);
    v.them(30);
    v.them(40);
    v.them(50);

    cout << "Cac phan tu cua Vector: ";
    v.in();

    cout << "Kich thuoc Vector: " << v.kichThuoc() << endl;
    cout << "Dung luong cua Vector: " << v.layDungLuong() << endl;

    cout << "Phan tu tai chi so 2: " << v.lay(2) << endl;

    v.xoa();
    cout << "Sau khi xoa: ";
    v.in();

    return 0;
}
