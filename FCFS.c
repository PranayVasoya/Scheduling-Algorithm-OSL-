#include <stdio.h>
int main() {
  int n;
  printf("Enter number of processes: ");
  scanf("%d", &n);
  int arrivalTime[n];
  int burstTime[n];
  int waitingTime[n];
  int turnaroundTime[n];
  // New array to store execution time
  int executionTime[n];
  printf("Enter arrival time for process:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arrivalTime[i]);
  }
  printf("Enter burst time for process:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &burstTime[i]);
  }
  int currentTime = 0;
  waitingTime[0] = 0;
  executionTime[0] = arrivalTime[0]; // Assuming process starts at its arrival time
  for (int i = 1; i < n; i++) {
    currentTime += burstTime[i - 1];
    waitingTime[i] = currentTime - arrivalTime[i];
    if (waitingTime[i] < 0)
      waitingTime[i] = 0;
    // Update execution time based on completion time
    executionTime[i] = currentTime + burstTime[i];
  }
  for (int i = 0; i < n; i++) {
    turnaroundTime[i] = burstTime[i] + waitingTime[i];
  }
  printf("P\tAT\tBT\tWT\tTAT\tET\n");
  float avgWT = 0, avgTAT = 0;
  for (int i = 0; i < n; i++) {
    printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, arrivalTime[i], burstTime[i], waitingTime[i], turnaroundTime[i], executionTime[i]);
    avgWT += waitingTime[i];
    avgTAT += turnaroundTime[i];
  }
  avgWT = avgWT / n;
  avgTAT = avgTAT / n;
  printf("\nAverage Waiting Time: %.2f\n", avgWT);
  printf("Average Turnaround Time: %.2f\n", avgTAT);
  return 0;
}