import java.util.ArrayList;

public class prior_que {

    private ArrayList<Integer> pq;
    private boolean isMaxHeap;

    public prior_que(int arr[], boolean isMax) {

        initialize(isMax);
        for (int ele : arr)
            pq.add(ele);
        constructHeap();

    }

    public void sort() {

        ArrayList<Integer> ans = new ArrayList<>();
        int i = 0;
        while (pq.size() > 0) {

            int top = pq.get(0);
            ans.add(top);
            pq.set(0, pq.get(pq.size() - 1));
            pq.remove(pq.size() - 1);
            downHeapify(0);
            // System.out.println("removed : "+top +"left is "+pq);

        }
        pq = ans;
        constructHeap();
        System.out.println(ans);

    }

    public void initialize(boolean isMax) {
        pq = new ArrayList<>();
        isMaxHeap = true;
    }

    public void constructHeap() {
        for (int i = pq.size() - 1; i >= 0; i--) {
            downHeapify(i);
        }
    }

    private int compareTo(int i, int j) {
        if (isMaxHeap)
            return pq.get(i) - pq.get(j);
        return pq.get(j) - pq.get(i);

    }

    public void swap(int i, int j) {
        int v1 = pq.get(i);
        int v2 = pq.get(j);
        pq.set(i, v2);
        pq.set(j, v1);
    }

    private void downHeapify(int idx) {

        int maxidx = idx;
        int li = (idx << 1) + 1;
        int ri = (idx << 1) + 2;
        if (li < pq.size() && compareTo(li, maxidx) > 0)
            maxidx = li;

        if (ri < pq.size() && compareTo(ri, maxidx) > 0)
            maxidx = ri;

        if (maxidx != idx) {
            swap(idx, maxidx);
            downHeapify(maxidx);
        }

    }

    public int size() {
        return pq.size();
    }

    public boolean isEmpty() {
        return pq.size() == 0;
    }

    public void add(int val) throws Exception {
        pq.add(val);
        upheapify(pq.size() - 1);
    }

    public void upheapify(int idx) {

        if (idx == 0)
            return;
        int pi = (idx - 1) / 2;
        if (pq.get(pi) < pq.get(idx)) {

            int swap = pq.get(idx);
            pq.set(idx, pq.get(pi));
            pq.set(pi, swap);
            upheapify(pi);
        }

    }

    public int peek() throws Exception {
        if (isEmpty())
            throw new Exception("NullPointerException");
        return pq.get(0);
    }

    public int poll() throws Exception {

        if (isEmpty())
            throw new Exception("NullPointerException");
        int val = pq.get(0);
        pq.set(0, pq.get(pq.size() - 1));
        pq.remove(pq.size() - 1);
        downHeapify(0);
        return val;

    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (int ele : pq) {
            sb.append(ele + " , ");
        }
        return sb.toString();
    }

}
