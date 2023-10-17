int root(int v) {
    return par[v] < 0
            ? v
            : (par[v] = root(par[v]));
}

void merge(int x, int y) {
    if ((x = root(x)) == (y = root(y)))  return ;
    
    if (par[y] < par[x])   swap(x, y);
    par[x] += par[y];
    par[y] = x;
}
