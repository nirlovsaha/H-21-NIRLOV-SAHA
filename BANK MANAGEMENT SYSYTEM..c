#include <stdio.h>
#include <stdlib.h>

struct account {
  int account_number;
  char name[100];
  float balance;
};

void create_account(struct account *account) {
  printf("Enter account number: ");
  scanf("%d", &account->account_number);

  printf("Enter name: ");
  scanf("%s", account->name);

  printf("\nEnter balance: ");
  scanf("%f", &account->balance);
}

void deposit_money(struct account *account, float amount) {
  account->balance += amount;
}

void withdraw_money(struct account *account, float amount) {
  if (account->balance < amount) {
    printf("Insufficient balance.\n");
    return;
  }

  account->balance -= amount;
}

void display_account(struct account *account) {
  printf("Account number: %d\n", account->account_number);
  printf("Name: %s\n", account->name);
  printf("Balance: %.2f\n", account->balance);
}

int main() {
  struct account accounts[100];
  int i, choice;

  while (1) {
    printf("\n1.Create account");
    printf("\n2. Deposit money");
    printf("\n3. Withdraw money");
    printf("\n4. Display account");
    printf("\n5. Exit");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    int account_number;
    switch (choice) {
      case 1:
        create_account(&accounts[i]);
        i++;
        break;

      case 2:
        printf("\nEnter account number: ");
        
        scanf("%d", &account_number);

        for (int j = 0; j < i; j++) {
          if (accounts[j].account_number == account_number) {
            printf("\nEnter amount to deposit: ");
            float amount;
            scanf("%f", &amount);

            deposit_money(&accounts[j], amount);
            break;
          }
        }
        break;

      case 3:
        printf("\nEnter account number: ");
        
        scanf("%d", &account_number);

        for (int j = 0; j < i; j++) {
          if (accounts[j].account_number == account_number) {
            printf("\nEnter amount to withdraw: ");
            float amount;
            scanf("%f", &amount);

            withdraw_money(&accounts[j], amount);
            break;
          }
        }
        break;

      case 4:
        printf("\nEnter account number: ");
        
        scanf("%d", &account_number);

        for (int j = 0; j < i; j++) {
          if (accounts[j].account_number == account_number) {
            display_account(&accounts[j]);
            break;
          }
        }
        break;

      case 5:
        exit(0);

      default:
        printf("Invalid choice.\n");
    }
  }

  return 0;
}