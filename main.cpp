#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
using int_vec = vector<int>;


int library_id_count = 0;
struct Library {
    int id;
    int N;
    int T;
    int M;

    int_vec books;
};


struct lib_ratio
{
    Library l;
    int ratio;
};

using lib_vectratio  = vector<lib_ratio>;


bool sort_lib(lib_ratio lhs, lib_ratio rhs)
{
    return lhs.ratio > rhs.ratio;
}


istream& operator>>(istream &in, Library &l)
{
    l.id = library_id_count++;
    in >> l.N >> l.T >> l.M;
    l.books.resize(l.N);
    for (auto &book: l.books)
        in >> book;

    return in;
}

ostream& operator<<(ostream &out, Library &l) {
    out << "Library #" << l.id << " {" << endl;
    out << "N: " << l.N << endl;
    out << "T: " << l.T << endl;
    out << "M: " << l.M << endl;
    out << "Books:" << endl;
    for (auto& book: l.books)
        out << book << " ";

    out << endl << "}" << endl;

    return out;
}

struct Output {
    vector<Library> libraries;
    vector<int_vec> books;


    void add_library(const Library &l, const int_vec &books);
    void dump() const;
};

void Output::add_library(const Library &l, const int_vec &b) {
    libraries.push_back(l);
    books.push_back(b);
}

void Output::dump() const {
    cout << libraries.size() << endl;
    for (auto i = 0u; i < libraries.size(); i++)
    {
        cout << libraries[i].id << " " << books[i].size() << endl;
        for (auto &b: books[i])
            cout << b << " ";
        cout << endl;
    }
}
vector<Library> libraries;
int B;
int L;
int D;

int_vec book_scores;

int ratio(Library l)
{
    if (l.T > D)
        return -1;
    //int a = accumulate(l.books.begin(), l.books.end(), 0);
    return l.N * l.M - l.T;// + a;
}

bool basic_sort(int a, int b)
{
    return book_scores[a] > book_scores[b];
}

void add_ratio(Output o)
{
    lib_vectratio lib_ratios;
    for(auto l : libraries)
    {
        sort(l.books.begin(), l.books.end(), basic_sort);
        lib_ratio lr { l, ratio(l)};
        lib_ratios.push_back(lr);
    }
    sort(lib_ratios.begin(), lib_ratios.end(), sort_lib);
    for(auto lr : lib_ratios)
    {
        o.add_library(lr.l, lr.l.books);
        if (D == 1)
            break;
        D--;
    }
    o.dump();
}

int main() {
    cin >> B >> L >> D;
    book_scores.resize(B);
    for (auto &book_score: book_scores)
        cin >> book_score;

    libraries.resize(L);
    for (auto &l: libraries)
        cin >> l;

    Output o;
    add_ratio(o);
    //o.add_library(libraries[0], libraries[0].books);
    //o.add_library(libraries[1], libraries[1].books);

    return 0;
}
