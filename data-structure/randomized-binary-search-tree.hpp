#pragma once
#include "../template/template.hpp"

template <class VAL>
struct RBST {
    VAL SUM_UNITY = 0;

    unsigned int randInt() {
        static unsigned int tx = 123456789, ty = 362436069, tz = 521288629, tw = 88675123;
        unsigned int tt = (tx ^ (tx << 11));
        tx = ty;
        ty = tz;
        tz = tw;
        return (tw = (tw ^ (tw >> 19)) ^ (tt ^ (tt >> 8)));
    }

    struct NODE {
        NODE *left, *right;
        VAL val;
        int size;
        VAL sum;

        NODE() : val(SUM_UNITY), size(1), sum(SUM_UNITY) {
            left = right = NULL;
        }

        NODE(VAL v) : val(v), size(1), sum(v) {
            left = right = NULL;
        }

        inline void update() {
        }

        inline void push() {
        }
    };
    NODE *root;
    RBST() : root(NULL) {}
    RBST(NODE *node) : root(node) {}

    inline int size(NODE *node) {
        return !node ? 0 : node->size;
    }
    inline int size() {
        return this->size(this->root);
    }

    inline VAL sum(NODE *node) {
        return !node ? SUM_UNITY : node->sum;
    }
    inline VAL sum() {
        return this->sum(this->root);
    }

    inline NODE *update(NODE *node) {
        node->size = size(node->left) + size(node->right) + 1;
        node->sum = sum(node->left) + sum(node->right) + node->val;
        node->update();
        return node;
    }

    inline void push(NODE *node) {
        if (!node) return;
        node->push();
    }

    inline int lowerBound(NODE *node, VAL val) {
        push(node);
        if (!node) return 0;
        if (val <= node->val)
            return lowerBound(node->left, val);
        else
            return size(node->left) + lowerBound(node->right, val) + 1;
    }
    inline int lowerBound(VAL val) {
        return this->lowerBound(this->root, val);
    }

    inline int upperBound(NODE *node, VAL val) {
        push(node);
        if (!node) return 0;
        if (val >= node->val)
            return size(node->left) + upperBound(node->right, val) + 1;
        else
            return upperBound(node->left, val);
    }
    inline int upperBound(VAL val) {
        return this->upperBound(this->root, val);
    }

    inline int count(VAL val) {
        return upperBound(val) - lowerBound(val);
    }

    inline VAL get(NODE *node, int k) {
        push(node);
        if (!node) return -1;
        if (k == size(node->left)) return node->val;
        if (k < size(node->left))
            return get(node->left, k);
        else
            return get(node->right, k - size(node->left) - 1);
    }
    inline VAL get(int k) {
        return get(this->root, k);
    }

    NODE *merge(NODE *left, NODE *right) {
        push(left);
        push(right);
        if (!left || !right) {
            if (left)
                return left;
            else
                return right;
        }
        if (randInt() % (left->size + right->size) < left->size) {
            left->right = merge(left->right, right);
            return update(left);
        } else {
            right->left = merge(left, right->left);
            return update(right);
        }
    }
    void merge(RBST add) {
        this->root = this->merge(this->root, add.root);
    }
    pair<NODE *, NODE *> split(NODE *node, int k) {  // [0, k), [k, n)
        push(node);
        if (!node) return make_pair(node, node);
        if (k <= size(node->left)) {
            pair<NODE *, NODE *> sub = split(node->left, k);
            node->left = sub.second;
            return make_pair(sub.first, update(node));
        } else {
            pair<NODE *, NODE *> sub = split(node->right, k - size(node->left) - 1);
            node->right = sub.first;
            return make_pair(update(node), sub.second);
        }
    }
    RBST split(int k) {
        pair<NODE *, NODE *> sub = split(this->root, k);
        this->root = sub.first;
        return RBST(sub.second);
    }

    void insert(const VAL val) {
        pair<NODE *, NODE *> sub = this->split(this->root, this->lowerBound(val));
        this->root = this->merge(this->merge(sub.first, new NODE(val)), sub.second);
    }

    void erase(const VAL val) {
        if (!this->count(val)) return;
        pair<NODE *, NODE *> sub = this->split(this->root, this->lowerBound(val));
        this->root = this->merge(sub.first, this->split(sub.second, 1).second);
    }

    void print(NODE *node) {
        if (!node) return;
        push(node);
        print(node->left);
        cout << node->val << " ";
        print(node->right);
    }
    void print() {
        cout << "{";
        print(this->root);
        cout << "}" << endl;
    }
};