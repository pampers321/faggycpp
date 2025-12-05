#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mult ll t; cin >> t; while (t--) { solve(); }
#define LOCAL

const ll INF = 1e18;
const int MOD = 1e9 + 7;
const ld EPS = 1e-9;
const int INf = 1e9;

template<class T>
T gcd_val(T a, T b) {
    while (b != 0) {
        T c = a % b;
        a = b;
        b = c;
    }
    return a;
}

template<class T>
T lcm_val(T a, T b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    return a / gcd_val(a, b) * b;
}

template<class T>
bool upd_max(T &cur, T val) {
    if (val > cur) {
        cur = val;
        return true;
    }
    return false;
}

template<class T>
bool upd_min(T &cur, T val) {
    if (val < cur) {
        cur = val;
        return true;
    }
    return false;
}

template<class T>
T abs_val(T x) {
    if (x < (T)0) {
        return -x;
    }
    return x;
}

template<class T>
T bin_pow(T base, ll exp) {
    T res = (T)1;
    while (exp > 0) {
        if (exp & 1) {
            res *= base;
        }
        base *= base;
        exp >>= 1;
    }
    return res;
}

template<class T>
T mod_pow(T base, ll exp, T mod) {
    base %= mod;
    if (base < 0) {
        base += mod;
    }
    T res = (T)1 % mod;
    while (exp > 0) {
        if (exp & 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

template<class T>
T ceil_div(T a, T b) {
    if (b < 0) {
        a = -a;
        b = -b;
    }
    if (a >= 0) {
        return (a + b - 1) / b;
    }
    return a / b;
}

template<class T>
T floor_div(T a, T b) {
    if (b < 0) {
        a = -a;
        b = -b;
    }
    if (a >= 0) {
        return a / b;
    }
    return (a - b + 1) / b;
}

bool is_prime(ll n) {
    if (n < 2) {
        return false;
    }
    if (n == 2 || n == 3) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    for (ll d = 3; d * d <= n; d += 2) {
        if (n % d == 0) {
            return false;
        }
    }
    return true;
}

vi sieve_primes(int n) {
    vi primes;
    vb used(n + 1, false);
    for (int i = 2; i <= n; i++) {
        if (!used[i]) {
            primes.push_back(i);
        }
        for (int j = 0; j < (int)primes.size(); j++) {
            int x = primes[j] * i;
            if (x > n) {
                break;
            }
            used[x] = true;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
    return primes;
}

ll euler_phi(ll n) {
    ll res = n;
    for (ll p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0) {
                n /= p;
            }
            res -= res / p;
        }
    }
    if (n > 1) {
        res -= res / n;
    }
    return res;
}


void solve() {
    cout << "MO-02/24b" << '\n';

    struct pr {
        string f;
        string i;
        string o;
        ll y;
    };

    enum ct {
        FIC,
        REF,
        EDU,
        OTH
    };

    struct ex : exception {
        string m;
        ex(const string &s) {
            m = s;
        }
        const char *what() const noexcept override {
            return m.c_str();
        }
    };

    class bk {
    protected:
        string n;
        ll p;
        vector<pr> a;
        string e;
        ll y;
        ct c;
    public:
        virtual ~bk() {
        }
        void sn(const string &s) {
            n = s;
        }
        void spg(ll v) {
            if (v < 0) {
                throw ex("pages<0");
            }
            p = v;
        }
        void sa(const vector<pr> &v) {
            a = v;
        }
        void se(const string &s) {
            e = s;
        }
        void sy(ll v) {
            if (v < 0) {
                throw ex("year<0");
            }
            y = v;
        }
        void sc(ct v) {
            c = v;
        }
        string gn() const {
            return n;
        }
        ll gp() const {
            return p;
        }
        vector<pr> ga() const {
            return a;
        }
        string ge() const {
            return e;
        }
        ll gy() const {
            return y;
        }
        ct gc() const {
            return c;
        }
        virtual string tp() const = 0;
    };

    class lbk : public bk {
        ll id;
        ll t;
        ll o;
    public:
        lbk() {
            id = 0;
            t = 0;
            o = 0;
        }
        void sid(ll v) {
            if (v < 0) {
                throw ex("id<0");
            }
            id = v;
        }
        void st(ll v) {
            if (v < 0) {
                throw ex("cnt<0");
            }
            t = v;
        }
        void so(ll v) {
            if (v < 0) {
                throw ex("out<0");
            }
            o = v;
        }
        ll gid() const {
            return id;
        }
        ll gt() const {
            return t;
        }
        ll go() const {
            return o;
        }
        ll av() const {
            return t - o;
        }
        string tp() const override {
            return "lib";
        }
    };

    class rd : public pr {
        ll id;
        bool ac;
        bool bl;
        ll ld;
        vll cur;
        vll all;
    public:
        rd() {
            id = 0;
            ac = true;
            bl = false;
            ld = 0;
        }
        void sid(ll v) {
            if (v < 0) {
                throw ex("rid<0");
            }
            id = v;
        }
        ll gid() const {
            return id;
        }
        void sa(bool v) {
            ac = v;
        }
        bool ga() const {
            return ac;
        }
        void sb(bool v) {
            bl = v;
        }
        bool gb() const {
            return bl;
        }
        void sl(ll v) {
            ld = v;
        }
        ll gl() const {
            return ld;
        }
        vll gk(bool h = true) const {
            if (h) {
                return cur;
            } else {
                return all;
            }
        }
        void ob(ll b) {
            bool fnd = false;
            for (ll i = 0; i < (ll)cur.size(); i++) {
                if (cur[i] == b) {
                    fnd = true;
                }
            }
            if (!fnd) {
                cur.push_back(b);
            }
            all.push_back(b);
        }
        void rb(ll b) {
            vll nc;
            for (ll i = 0; i < (ll)cur.size(); i++) {
                if (cur[i] != b) {
                    nc.push_back(cur[i]);
                }
            }
            cur = nc;
        }
    };

    struct op {
        ll id;
        ll r;
        ll b;
        ll s;
        ll f;
        bool w;
    };

    struct mn {
        vector<lbk> bs;
        vector<rd> rs;
        vector<op> os;
        ll cd;
        ll nb;
        ll nr;
        ll no_;

        mn() {
            cd = 0;
            nb = 1;
            nr = 1;
            no_ = 1;
        }

        void rin(ll &x, ll l, ll r, const string &p) {
            while (true) {
                cout << p << " [" << l << "-" << r << "]: ";
                if (!(cin >> x)) {
                    cin.clear();
                    string t;
                    getline(cin, t);
                    cout << "Некорректный ввод, повторите" << '\n';
                } else {
                    if (x < l || x > r) {
                        cout << "Число должно быть от " << l << " до " << r << '\n';
                    } else {
                        break;
                    }
                }
            }
        }

        string rstr(const string &p) {
            cout << p << ": ";
            string s;
            getline(cin, s);
            while ((ll)s.size() == 0) {
                getline(cin, s);
            }
            return s;
        }

        pr rper() {
            pr pp;
            string s;
            cout << "Фамилия: ";
            getline(cin, s);
            while ((ll)s.size() == 0) {
                getline(cin, s);
            }
            pp.f = s;
            cout << "Имя: ";
            s.clear();
            getline(cin, s);
            while ((ll)s.size() == 0) {
                getline(cin, s);
            }
            pp.i = s;
            cout << "Отчество: ";
            s.clear();
            getline(cin, s);
            while ((ll)s.size() == 0) {
                getline(cin, s);
            }
            pp.o = s;
            ll yy;
            rin(yy, 0, 3000, "Год рождения");
            pp.y = yy;
            return pp;
        }

        lbk *fb(ll id) {
            for (ll i = 0; i < (ll)bs.size(); i++) {
                if (bs[i].gid() == id) {
                    return &bs[i];
                }
            }
            return nullptr;
        }

        rd *fr(ll id) {
            for (ll i = 0; i < (ll)rs.size(); i++) {
                if (rs[i].gid() == id) {
                    return &rs[i];
                }
            }
            return nullptr;
        }

        void addb() {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            lbk b;
            b.sid(nb);
            nb++;
            string s = rstr("Название");
            b.sn(s);
            ll pg;
            rin(pg, 1, 100000, "Страниц");
            b.spg(pg);
            cout << "Издательство: ";
            string ee;
            getline(cin, ee);
            while ((ll)ee.size() == 0) {
                getline(cin, ee);
            }
            b.se(ee);
            ll yy;
            rin(yy, 0, 3000, "Год издания");
            b.sy(yy);
            ll ctv;
            rin(ctv, 0, 3, "Категория (0-худ,1-справ,2-учеб,3-др)");
            if (ctv == 0) {
                b.sc(FIC);
            } else {
                if (ctv == 1) {
                    b.sc(REF);
                } else {
                    if (ctv == 2) {
                        b.sc(EDU);
                    } else {
                        b.sc(OTH);
                    }
                }
            }
            ll ac;
            rin(ac, 1, 1000, "Общее количество экземпляров");
            b.st(ac);
            b.so(0);
            ll na;
            rin(na, 1, 5, "Количество авторов");
            vector<pr> pa;
            for (ll i = 0; i < na; i++) {
                cout << "Автор " << i + 1 << '\n';
                pr pp = rper();
                pa.push_back(pp);
            }
            b.sa(pa);
            bs.push_back(b);
            cout << "Книга добавлена, ID=" << b.gid() << '\n';
        }

        void addr() {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            rd r;
            r.sid(nr);
            nr++;
            pr pp = rper();
            r.f = pp.f;
            r.i = pp.i;
            r.o = pp.o;
            r.y = pp.y;
            r.sa(true);
            r.sb(false);
            r.sl(cd);
            rs.push_back(r);
            cout << "Читатель добавлен, ID=" << r.gid() << '\n';
        }

        void iss(ll rid, ll bid) {
            rd *r = fr(rid);
            if (r == nullptr) {
                throw ex("Нет такого читателя");
            }
            lbk *b = fb(bid);
            if (b == nullptr) {
                throw ex("Нет такой книги");
            }
            if (!r->ga()) {
                throw ex("Читатель не активен");
            }
            if (r->gb()) {
                throw ex("Читатель заблокирован");
            }
            vll cur = r->gk(true);
            if ((ll)cur.size() >= 3) {
                throw ex("Не более 3 книг");
            }
            for (ll i = 0; i < (ll)cur.size(); i++) {
                if (cur[i] == bid) {
                    throw ex("Эта книга уже на руках");
                }
            }
            if (b->av() <= 0) {
                throw ex("Нет доступных экземпляров");
            }
            op o;
            o.id = no_;
            no_++;
            o.r = rid;
            o.b = bid;
            o.s = cd;
            o.f = -1;
            o.w = false;
            os.push_back(o);
            r->ob(bid);
            r->sl(cd);
            b->so(b->go() + 1);
            cout << "Книга выдана" << '\n';
        }

        void ret(ll rid, ll bid) {
            rd *r = fr(rid);
            if (r == nullptr) {
                throw ex("Нет такого читателя");
            }
            lbk *b = fb(bid);
            if (b == nullptr) {
                throw ex("Нет такой книги");
            }
            vll cur = r->gk(true);
            bool fnd = false;
            for (ll i = 0; i < (ll)cur.size(); i++) {
                if (cur[i] == bid) {
                    fnd = true;
                }
            }
            if (!fnd) {
                throw ex("У читателя нет этой книги");
            }
            op *po = nullptr;
            for (ll i = 0; i < (ll)os.size(); i++) {
                if (os[i].r == rid && os[i].b == bid && os[i].f == -1 && !os[i].w) {
                    po = &os[i];
                    break;
                }
            }
            if (po == nullptr) {
                throw ex("Операция не найдена");
            }
            po->f = cd;
            r->rb(bid);
            r->sl(cd);
            b->so(b->go() - 1);
            cout << "Книга возвращена" << '\n';
        }

        void adv(ll d) {
            if (d < 0) {
                throw ex("Отрицательное время");
            }
            cd += d;
            for (ll i = 0; i < (ll)rs.size(); i++) {
                if (cd - rs[i].gl() > 366 && rs[i].ga()) {
                    rs[i].sa(false);
                }
            }
            for (ll i = 0; i < (ll)os.size(); i++) {
                if (os[i].f == -1 && !os[i].w) {
                    if (cd - os[i].s > 366) {
                        os[i].w = true;
                        rd *r = fr(os[i].r);
                        lbk *b = fb(os[i].b);
                        if (r != nullptr) {
                            r->sb(true);
                            r->sa(false);
                            r->rb(os[i].b);
                        }
                        if (b != nullptr) {
                            if (b->go() > 0) {
                                b->so(b->go() - 1);
                            }
                        }
                    }
                }
            }
            cout << "Текущее время: день " << cd << '\n';
        }

        void savb() {
            ofstream f("books.txt");
            if (!f) {
                cout << "Ошибка файла книг" << '\n';
                return;
            }
            f << (ll)bs.size() << '\n';
            for (ll i = 0; i < (ll)bs.size(); i++) {
                lbk &b = bs[i];
                f << b.gid() << '|' << b.gt() << '|' << b.go() << '|';
                f << b.gn() << '|' << b.gp() << '|' << b.ge() << '|' << b.gy() << '|';
                f << (ll)b.gc() << '|';
                vector<pr> pa = b.ga();
                f << (ll)pa.size();
                for (ll j = 0; j < (ll)pa.size(); j++) {
                    f << '|' << pa[j].f << '|' << pa[j].i << '|' << pa[j].o << '|' << pa[j].y;
                }
                f << '\n';
            }
            cout << "Книги сохранены" << '\n';
        }

        void savr() {
            ofstream f("readers.txt");
            if (!f) {
                cout << "Ошибка файла читателей" << '\n';
                return;
            }
            f << (ll)rs.size() << '\n';
            for (ll i = 0; i < (ll)rs.size(); i++) {
                rd &r = rs[i];
                f << r.gid() << '|' << (r.ga() ? 1 : 0) << '|' << (r.gb() ? 1 : 0) << '|' << r.gl() << '|';
                f << r.f << '|' << r.i << '|' << r.o << '|' << r.y << '\n';
            }
            cout << "Читатели сохранены" << '\n';
        }

        void savo() {
            ofstream f("ops.txt");
            if (!f) {
                cout << "Ошибка файла операций" << '\n';
                return;
            }
            f << cd << '\n';
            f << (ll)os.size() << '\n';
            for (ll i = 0; i < (ll)os.size(); i++) {
                op &o = os[i];
                f << o.id << '|' << o.r << '|' << o.b << '|' << o.s << '|' << o.f << '|' << (o.w ? 1 : 0) << '\n';
            }
            cout << "Операции сохранены" << '\n';
        }

        vector<string> sp(const string &s, char d) {
            vector<string> v;
            string cur;
            for (ll i = 0; i < (ll)s.size(); i++) {
                char ch = s[i];
                if (ch == d) {
                    v.push_back(cur);
                    cur.clear();
                } else {
                    cur.push_back(ch);
                }
            }
            v.push_back(cur);
            return v;
        }

        void loadb() {
            ifstream f("books.txt");
            if (!f) {
                cout << "Файл книг не найден" << '\n';
                return;
            }
            bs.clear();
            string ln;
            if (!getline(f, ln)) {
                return;
            }
            ll cnt = stoll(ln);
            for (ll k = 0; k < cnt; k++) {
                if (!getline(f, ln)) {
                    break;
                }
                vector<string> v = sp(ln, '|');
                if ((ll)v.size() < 8) {
                    continue;
                }
                lbk b;
                b.sid(stoll(v[0]));
                b.st(stoll(v[1]));
                b.so(stoll(v[2]));
                b.sn(v[3]);
                b.spg(stoll(v[4]));
                b.se(v[5]);
                b.sy(stoll(v[6]));
                ll ctv = stoll(v[7]);
                if (ctv == 0) {
                    b.sc(FIC);
                } else {
                    if (ctv == 1) {
                        b.sc(REF);
                    } else {
                        if (ctv == 2) {
                            b.sc(EDU);
                        } else {
                            b.sc(OTH);
                        }
                    }
                }
                vector<pr> pa;
                if ((ll)v.size() > 8) {
                    ll pos = 8;
                    ll na = stoll(v[pos]);
                    pos++;
                    for (ll i = 0; i < na; i++) {
                        if (pos + 3 >= (ll)v.size()) {
                            break;
                        }
                        pr ppp;
                        ppp.f = v[pos];
                        pos++;
                        ppp.i = v[pos];
                        pos++;
                        ppp.o = v[pos];
                        pos++;
                        ppp.y = stoll(v[pos]);
                        pos++;
                        pa.push_back(ppp);
                    }
                }
                b.sa(pa);
                bs.push_back(b);
                if (b.gid() + 1 > nb) {
                    nb = b.gid() + 1;
                }
            }
            cout << "Книги загружены" << '\n';
        }

        void loadr() {
            ifstream f("readers.txt");
            if (!f) {
                cout << "Файл читателей не найден" << '\n';
                return;
            }
            rs.clear();
            string ln;
            if (!getline(f, ln)) {
                return;
            }
            ll cnt = stoll(ln);
            for (ll k = 0; k < cnt; k++) {
                if (!getline(f, ln)) {
                    break;
                }
                vector<string> v = sp(ln, '|');
                if ((ll)v.size() < 8) {
                    continue;
                }
                rd r;
                r.sid(stoll(v[0]));
                r.sa(stoll(v[1]) != 0);
                r.sb(stoll(v[2]) != 0);
                r.sl(stoll(v[3]));
                r.f = v[4];
                r.i = v[5];
                r.o = v[6];
                r.y = stoll(v[7]);
                rs.push_back(r);
                if (r.gid() + 1 > nr) {
                    nr = r.gid() + 1;
                }
            }
            cout << "Читатели загружены" << '\n';
        }

        void loado() {
            ifstream f("ops.txt");
            if (!f) {
                cout << "Файл операций не найден" << '\n';
                return;
            }
            os.clear();
            string ln;
            if (!getline(f, ln)) {
                return;
            }
            cd = stoll(ln);
            if (!getline(f, ln)) {
                return;
            }
            ll cnt = stoll(ln);
            for (ll k = 0; k < cnt; k++) {
                if (!getline(f, ln)) {
                    break;
                }
                vector<string> v = sp(ln, '|');
                if ((ll)v.size() < 6) {
                    continue;
                }
                op o;
                o.id = stoll(v[0]);
                o.r = stoll(v[1]);
                o.b = stoll(v[2]);
                o.s = stoll(v[3]);
                o.f = stoll(v[4]);
                o.w = (stoll(v[5]) != 0);
                os.push_back(o);
                if (o.id + 1 > no_) {
                    no_ = o.id + 1;
                }
            }
            cout << "Операции загружены, день " << cd << '\n';
        }

        void lstb() {
            if ((ll)bs.size() == 0) {
                cout << "Пусто" << '\n';
                return;
            }
            ll pg = 0;
            while (true) {
                ll n = (ll)bs.size();
                ll l = pg * 10;
                if (l >= n) {
                    pg = 0;
                    l = 0;
                }
                ll r = l + 10;
                if (r > n) {
                    r = n;
                }
                for (ll i = l; i < r; i++) {
                    lbk &b = bs[i];
                    cout << "ID=" << b.gid() << " \"" << b.gn() << "\" стр=" << b.gp() << " год=" << b.gy() << " всего=" << b.gt() << " доступно=" << b.av() << '\n';
                }
                cout << "Страница " << pg + 1 << " из " << ((n + 9) / 10) << " (n-next, p-prev, q-back): ";
                char ch;
                cin >> ch;
                if (ch == 'n') {
                    if ((pg + 1) * 10 < n) {
                        pg++;
                    }
                } else {
                    if (ch == 'p') {
                        if (pg > 0) {
                            pg--;
                        }
                    } else {
                        if (ch == 'q') {
                            break;
                        }
                    }
                }
            }
        }

        void lstr() {
            if ((ll)rs.size() == 0) {
                cout << "Пусто" << '\n';
                return;
            }
            ll pg = 0;
            while (true) {
                ll n = (ll)rs.size();
                ll l = pg * 10;
                if (l >= n) {
                    pg = 0;
                    l = 0;
                }
                ll r = l + 10;
                if (r > n) {
                    r = n;
                }
                for (ll i = l; i < r; i++) {
                    rd &rdd = rs[i];
                    cout << "ID=" << rdd.gid() << " " << rdd.f << " " << rdd.i << " " << rdd.o << " год=" << rdd.y << " активен=" << (rdd.ga() ? "да" : "нет") << " блок=" << (rdd.gb() ? "да" : "нет") << '\n';
                }
                cout << "Страница " << pg + 1 << " из " << ((n + 9) / 10) << " (n-next, p-prev, q-back): ";
                char ch;
                cin >> ch;
                if (ch == 'n') {
                    if ((pg + 1) * 10 < n) {
                        pg++;
                    }
                } else {
                    if (ch == 'p') {
                        if (pg > 0) {
                            pg--;
                        }
                    } else {
                        if (ch == 'q') {
                            break;
                        }
                    }
                }
            }
        }

        void rep_debt() {
            struct dd {
                ll id;
                ll c;
            };
            vector<dd> v;
            for (ll i = 0; i < (ll)rs.size(); i++) {
                rd &r = rs[i];
                ll rid = r.gid();
                ll cnt = 0;
                for (ll j = 0; j < (ll)os.size(); j++) {
                    if (os[j].r == rid && os[j].f == -1 && !os[j].w) {
                        if (cd - os[j].s > 30) {
                            cnt++;
                        }
                    }
                }
                if (cnt > 0) {
                    dd tmp;
                    tmp.id = rid;
                    tmp.c = cnt;
                    v.push_back(tmp);
                }
            }
            if ((ll)v.size() == 0) {
                cout << "Должников нет" << '\n';
                return;
            }
            struct cmp {
                static bool cmpf(const dd &a, const dd &b) {
                    if (a.c > b.c) {
                        return true;
                    }
                    if (a.c < b.c) {
                        return false;
                    }
                    return a.id < b.id;
                }
            };
            sort(v.begin(), v.end(), cmp::cmpf);
            ll pg = 0;
            while (true) {
                ll n = (ll)v.size();
                ll l = pg * 10;
                if (l >= n) {
                    pg = 0;
                    l = 0;
                }
                ll r = l + 10;
                if (r > n) {
                    r = n;
                }
                for (ll i = l; i < r; i++) {
                    rd *r = fr(v[i].id);
                    if (r != nullptr) {
                        cout << "ID=" << r->gid() << " " << r->f << " " << r->i << " " << r->o << " просроченных=" << v[i].c << '\n';
                    }
                }
                cout << "Страница " << pg + 1 << " из " << ((n + 9) / 10) << " (n-next, p-prev, q-back): ";
                char ch;
                cin >> ch;
                if (ch == 'n') {
                    if ((pg + 1) * 10 < n) {
                        pg++;
                    }
                } else {
                    if (ch == 'p') {
                        if (pg > 0) {
                            pg--;
                        }
                    } else {
                        if (ch == 'q') {
                            break;
                        }
                    }
                }
            }
        }

        void rep_pop() {
            struct dd {
                ll id;
                ll c;
            };
            map<ll, ll> mp;
            for (ll i = 0; i < (ll)os.size(); i++) {
                mp[os[i].b]++;
            }
            vector<dd> v;
            for (auto it = mp.begin(); it != mp.end(); it++) {
                dd tmp;
                tmp.id = it->first;
                tmp.c = it->second;
                v.push_back(tmp);
            }
            if ((ll)v.size() == 0) {
                cout << "Операций нет" << '\n';
                return;
            }
            struct cmp {
                static bool cmpf(const dd &a, const dd &b) {
                    if (a.c > b.c) {
                        return true;
                    }
                    if (a.c < b.c) {
                        return false;
                    }
                    return a.id < b.id;
                }
            };
            sort(v.begin(), v.end(), cmp::cmpf);
            ll pg = 0;
            while (true) {
                ll n = (ll)v.size();
                ll l = pg * 10;
                if (l >= n) {
                    pg = 0;
                    l = 0;
                }
                ll r = l + 10;
                if (r > n) {
                    r = n;
                }
                for (ll i = l; i < r; i++) {
                    lbk *b = fb(v[i].id);
                    if (b != nullptr) {
                        cout << "ID=" << b->gid() << " \"" << b->gn() << "\" выдач=" << v[i].c << '\n';
                    }
                }
                cout << "Страница " << pg + 1 << " из " << ((n + 9) / 10) << " (n-next, p-prev, q-back): ";
                char ch;
                cin >> ch;
                if (ch == 'n') {
                    if ((pg + 1) * 10 < n) {
                        pg++;
                    }
                } else {
                    if (ch == 'p') {
                        if (pg > 0) {
                            pg--;
                        }
                    } else {
                        if (ch == 'q') {
                            break;
                        }
                    }
                }
            }
        }

        void rep_act() {
            struct dd {
                ll id;
                ll c;
            };
            map<ll, ll> mp;
            for (ll i = 0; i < (ll)os.size(); i++) {
                mp[os[i].r]++;
            }
            vector<dd> v;
            for (auto it = mp.begin(); it != mp.end(); it++) {
                dd tmp;
                tmp.id = it->first;
                tmp.c = it->second;
                v.push_back(tmp);
            }
            if ((ll)v.size() == 0) {
                cout << "Операций нет" << '\n';
                return;
            }
            struct cmp {
                static bool cmpf(const dd &a, const dd &b) {
                    if (a.c > b.c) {
                        return true;
                    }
                    if (a.c < b.c) {
                        return false;
                    }
                    return a.id < b.id;
                }
            };
            sort(v.begin(), v.end(), cmp::cmpf);
            ll pg = 0;
            while (true) {
                ll n = (ll)v.size();
                ll l = pg * 10;
                if (l >= n) {
                    pg = 0;
                    l = 0;
                }
                ll r = l + 10;
                if (r > n) {
                    r = n;
                }
                for (ll i = l; i < r; i++) {
                    rd *r = fr(v[i].id);
                    if (r != nullptr) {
                        cout << "ID=" << r->gid() << " " << r->f << " " << r->i << " " << r->o << " операций=" << v[i].c << '\n';
                    }
                }
                cout << "Страница " << pg + 1 << " из " << ((n + 9) / 10) << " (n-next, p-prev, q-back): ";
                char ch;
                cin >> ch;
                if (ch == 'n') {
                    if ((pg + 1) * 10 < n) {
                        pg++;
                    }
                } else {
                    if (ch == 'p') {
                        if (pg > 0) {
                            pg--;
                        }
                    } else {
                        if (ch == 'q') {
                            break;
                        }
                    }
                }
            }
        }

        void rep_bad() {
            struct dd {
                ll id;
                long long c;
            };
            map<ll, long long> mp;
            for (ll i = 0; i < (ll)os.size(); i++) {
                ll endd;
                if (os[i].f == -1) {
                    endd = cd;
                } else {
                    endd = os[i].f;
                }
                long long over = (long long)endd - (long long)(os[i].s + 30);
                if (over > 0) {
                    mp[os[i].r] += over;
                }
            }
            vector<dd> v;
            for (auto it = mp.begin(); it != mp.end(); it++) {
                dd tmp;
                tmp.id = it->first;
                tmp.c = it->second;
                v.push_back(tmp);
            }
            if ((ll)v.size() == 0) {
                cout << "Просрочек нет" << '\n';
                return;
            }
            struct cmp {
                static bool cmpf(const dd &a, const dd &b) {
                    if (a.c > b.c) {
                        return true;
                    }
                    if (a.c < b.c) {
                        return false;
                    }
                    return a.id < b.id;
                }
            };
            sort(v.begin(), v.end(), cmp::cmpf);
            ll pg = 0;
            while (true) {
                ll n = (ll)v.size();
                ll l = pg * 10;
                if (l >= n) {
                    pg = 0;
                    l = 0;
                }
                ll r = l + 10;
                if (r > n) {
                    r = n;
                }
                for (ll i = l; i < r; i++) {
                    rd *r = fr(v[i].id);
                    if (r != nullptr) {
                        cout << "ID=" << r->gid() << " " << r->f << " " << r->i << " " << r->o << " просрочено дней=" << v[i].c << '\n';
                    }
                }
                cout << "Страница " << pg + 1 << " из " << ((n + 9) / 10) << " (n-next, p-prev, q-back): ";
                char ch;
                cin >> ch;
                if (ch == 'n') {
                    if ((pg + 1) * 10 < n) {
                        pg++;
                    }
                } else {
                    if (ch == 'p') {
                        if (pg > 0) {
                            pg--;
                        }
                    } else {
                        if (ch == 'q') {
                            break;
                        }
                    }
                }
            }
        }

        void rep_w() {
            vector<op *> v;
            for (ll i = 0; i < (ll)os.size(); i++) {
                if (os[i].w) {
                    v.push_back(&os[i]);
                }
            }
            if ((ll)v.size() == 0) {
                cout << "Списанных книг нет" << '\n';
                return;
            }
            ll pg = 0;
            while (true) {
                ll n = (ll)v.size();
                ll l = pg * 10;
                if (l >= n) {
                    pg = 0;
                    l = 0;
                }
                ll r = l + 10;
                if (r > n) {
                    r = n;
                }
                for (ll i = l; i < r; i++) {
                    op *o = v[i];
                    lbk *b = fb(o->b);
                    rd *r = fr(o->r);
                    cout << "opID=" << o->id << " книгаID=" << o->b;
                    if (b != nullptr) {
                        cout << " \"" << b->gn() << "\"";
                    }
                    cout << " читательID=" << o->r;
                    if (r != nullptr) {
                        cout << " " << r->f << " " << r->i << " " << r->o;
                    }
                    cout << " дата=" << o->s << '\n';
                }
                cout << "Страница " << pg + 1 << " из " << ((n + 9) / 10) << " (n-next, p-prev, q-back): ";
                char ch;
                cin >> ch;
                if (ch == 'n') {
                    if ((pg + 1) * 10 < n) {
                        pg++;
                    }
                } else {
                    if (ch == 'p') {
                        if (pg > 0) {
                            pg--;
                        }
                    } else {
                        if (ch == 'q') {
                            break;
                        }
                    }
                }
            }
        }

        void rep_ops() {
            if ((ll)os.size() == 0) {
                cout << "Операций нет" << '\n';
                return;
            }
            ll pg = 0;
            while (true) {
                ll n = (ll)os.size();
                ll l = pg * 10;
                if (l >= n) {
                    pg = 0;
                    l = 0;
                }
                ll r = l + 10;
                if (r > n) {
                    r = n;
                }
                for (ll i = l; i < r; i++) {
                    op &o = os[i];
                    lbk *b = fb(o.b);
                    rd *r = fr(o.r);
                    cout << "ID=" << o.id << " день=" << o.s << " читательID=" << o.r;
                    if (r != nullptr) {
                        cout << " " << r->f << " " << r->i << " " << r->o;
                    }
                    cout << " книгаID=" << o.b;
                    if (b != nullptr) {
                        cout << " \"" << b->gn() << "\"";
                    }
                    cout << " возврат=" << o.f << " списана=" << (o.w ? "да" : "нет") << '\n';
                }
                cout << "Страница " << pg + 1 << " из " << ((n + 9) / 10) << " (n-next, p-prev, q-back): ";
                char ch;
                cin >> ch;
                if (ch == 'n') {
                    if ((pg + 1) * 10 < n) {
                        pg++;
                    }
                } else {
                    if (ch == 'p') {
                        if (pg > 0) {
                            pg--;
                        }
                    } else {
                        if (ch == 'q') {
                            break;
                        }
                    }
                }
            }
        }

        void rep() {
            while (true) {
                cout << "Отчеты: 1-должники 2-популярные книги 3-активные читатели 4-неблагонадежные 5-списанные книги 6-операции 0-выход" << '\n';
                ll x;
                rin(x, 0, 6, "Выбор");
                if (x == 0) {
                    break;
                }
                try {
                    if (x == 1) {
                        rep_debt();
                    } else {
                        if (x == 2) {
                            rep_pop();
                        } else {
                            if (x == 3) {
                                rep_act();
                            } else {
                                if (x == 4) {
                                    rep_bad();
                                } else {
                                    if (x == 5) {
                                        rep_w();
                                    } else {
                                        if (x == 6) {
                                            rep_ops();
                                        }
                                    }
                                }
                            }
                        }
                    }
                } catch (ex &e) {
                    cout << "Ошибка: " << e.what() << '\n';
                }
            }
        }

        void run() {
            while (true) {
                cout << '\n';
                cout << "Меню:" << '\n';
                cout << "1 - добавить книгу" << '\n';
                cout << "2 - добавить читателя" << '\n';
                cout << "3 - список книг" << '\n';
                cout << "4 - список читателей" << '\n';
                cout << "5 - выдать книгу" << '\n';
                cout << "6 - принять книгу" << '\n';
                cout << "7 - пропустить время" << '\n';
                cout << "8 - отчеты" << '\n';
                cout << "9 - сохранить все" << '\n';
                cout << "10 - загрузить все" << '\n';
                cout << "0 - выход" << '\n';
                ll ch;
                rin(ch, 0, 10, "Выбор");
                if (ch == 0) {
                    break;
                }
                try {
                    if (ch == 1) {
                        addb();
                    } else {
                        if (ch == 2) {
                            addr();
                        } else {
                            if (ch == 3) {
                                lstb();
                            } else {
                                if (ch == 4) {
                                    lstr();
                                } else {
                                    if (ch == 5) {
                                        ll rid;
                                        ll bid;
                                        rin(rid, 1, (ll)1e9, "ID читателя");
                                        rin(bid, 1, (ll)1e9, "ID книги");
                                        iss(rid, bid);
                                    } else {
                                        if (ch == 6) {
                                            ll rid;
                                            ll bid;
                                            rin(rid, 1, (ll)1e9, "ID читателя");
                                            rin(bid, 1, (ll)1e9, "ID книги");
                                            ret(rid, bid);
                                        } else {
                                            if (ch == 7) {
                                                ll d;
                                                rin(d, 0, (ll)1e9, "Количество дней");
                                                adv(d);
                                            } else {
                                                if (ch == 8) {
                                                    rep();
                                                } else {
                                                    if (ch == 9) {
                                                        savb();
                                                        savr();
                                                        savo();
                                                    } else {
                                                        if (ch == 10) {
                                                            loadb();
                                                            loadr();
                                                            loado();
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } catch (ex &e) {
                    cout << "Ошибка: " << e.what() << '\n';
                }
            }
        }
    };

    mn m;
    m.run();
}




int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    //fast_io;
    solve();
    //mult;
    return 0;
}
