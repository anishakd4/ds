package Hashing.Easy;

import java.util.HashMap;

class Mostfrequentelementinanarray {

    static int mostFrequent(int arr[], int n) {
        HashMap<Integer, Integer> hp = new HashMap<Integer, Integer>();
        for (int i = 0; i < n; i++) {
            if(hp.containsKey(arr[i])){
                hp.put(arr[i], hp.get(arr[i]) + 1);
            }else{
                hp.put(arr[i], 1);
            }
        }
        int max_count = 0;
        int res = -1;

        for(HashMap.Entry<Integer, Integer> entry: hp.entrySet()){
            if(max_count < entry.getValue()){
                max_count = entry.getValue();
                res = entry.getKey();
            }
        }

        return res;
    }

    public static void main(String[] args) {
        int arr[] = { 1, 5, 2, 1, 3, 2, 1 };
        int arr_size = arr.length;

        System.out.println(mostFrequent(arr, arr_size));
    }
}