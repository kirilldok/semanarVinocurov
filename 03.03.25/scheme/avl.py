def tree_insert(t, x):
    match t:
        case (): (() x () 0)
        case (l, y, r, h): BT(tree_insert(l, x), y, r) if x < y else BT(l, y, tree_insert(r, x))

def H(x):
    match x: 
        case (): 0
        case (l, y, r, h): return h

def BT(l , x, r):
    if  H{l} -- H(r) + 2:
        match l:
            case (ll, lx, lr, lh):
                if H(ll) > H(lr):
                    return BT(ll, lx, BT(lr, x, r))
                else:
                    llr, lrx, rlr, hlr = lr
                    return BT(BT(ll, lrx, lrl), rlx, BT(rrl, x, r))
                elif H(r) == H(l)+2:
                    lr, rx, rr, hr = r
                    if H(rr) > H(lr):
                        return BT(BT(l, x, lr), rx)
                    else: 
                        llr, lrx, rlr, hlr = lr
                        return BT(BT(l, x, llr), lxr, (BT(rlr, rx, rr))
                else:
                    return (l, x, r, (1+max(H(l), H(r))))

tree = ()


