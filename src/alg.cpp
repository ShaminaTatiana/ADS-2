// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
int cnt = 0;
for (int i = 0; i < len-1; i++) {
  for (int j = i+1; j < len; j++) {
    if ((arr[i] + arr[j]) == value) cnt++;
  }
}
return cnt;
}

int countPairs2(int *arr, int len, int value) {
int cnt = 0, r = len - 1, l = 0;
while (l < r-1) {
  int mid = (l + r) / 2;
  if (arr[mid] <= value)
    l = mid;
  else
    r = mid;
}
len = r - 1;
for (int i = len; i >= 0; i--) {
  for (int j = 0; j < i; j++) {
    if (arr[i] + arr[j] == value)
      cnt++;
    if (arr[i] + arr[j] > value)
      break;
    }
  }
return cnt;
}

int countPairs3(int *arr, int len, int value) {
int cnt = 0, r = len - 1, l = 0;
  while (l < r - 1) {
    int mid = (l + r) / 2;
    if (arr[mid] <= value)
      l = mid;
    else
      r = mid;
  }
len = r - 1;

for (int i = 0; i < len; i++) {
  l = i + 1, r = len - 1;
  int cntKol = 0;
  while (l < r) {
    int mid = (l + r) / 2;
    if (arr[mid] < (value - arr[i]))
      l = mid + 1;
    else
      r = mid;
  }
  while (arr[l] == (value - arr[i])) {
    cntKol++;
    l++;
    }
  cnt += cntKol;
  }
return cnt;
}
