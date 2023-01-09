template <class T>
struct sectionsum {
    vector<T> data;

    sectionsum(int n) : data(n + 1, 0) {}

    void update(int k, const T& x) {
        data[k + 1] = x;
    }

    void build() {
        for (int i = 1; i < (int)data.size(); i++) {
            data[i] += data[i - 1];
        }
    }

    T get(int r) const {
        assert(r >= 0 && r < (int)data.size());
        return data[r];
    }
    T get(int l, int r) const {
        return get(r) - get(l);
    }
};