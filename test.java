public class ReportGenerator {
    public void generateDailyReport(List<Transaction> transactions) {
        double total = 0;
        for (Transaction t : transactions) {
            if (t.getDate().equals(LocalDate.now())) {
                total += t.getAmount();
            }
        }
        
        System.out.println("Daily Report");
        System.out.println("------------");
        System.out.println("Total: $" + total);
        System.out.println("Date: " + LocalDate.now());
        saveReport("daily", total);
    }
    
    public void generateWeeklyReport(List<Transaction> transactions) {
        LocalDate weekStart = LocalDate.now().minusDays(7);
        
        double sum = 0;
        for (Transaction transaction : transactions) {
            if (transaction.getDate().isAfter(weekStart) || transaction.getDate().equals(weekStart)) {
                sum = sum + transaction.getAmount();
            }
        }
        
        System.out.println("Weekly Report");
        System.out.println("-------------");
        System.out.println("Total: $" + sum);
        System.out.println("Period: " + weekStart + " to " + LocalDate.now());
        
        // Save to database
        saveReport("weekly", sum);
    }
    
    private void saveReport(String type, double amount) {
        // Save to database
    }
}

public class ReportGenerator {
    public void generateDailyReport(List<Transaction> transactions) {
        LocalDate startDate = LocalDate.now();
        double total = calculateTotal(transactions, startDate);
        
        printReport("Daily Report", total, startDate, LocalDate.now());
        saveReport("daily", total);
    }
    
    public void generateWeeklyReport(List<Transaction> transactions) {
        LocalDate startDate = LocalDate.now().minusDays(7);
        double total = calculateTotal(transactions, startDate);
        
        printReport("Weekly Report", total, startDate, LocalDate.now());
        saveReport("weekly", total);
    }
    
    private double calculateTotal(List<Transaction> transactions, LocalDate startDate) {
        double total = 0;
        for (Transaction t : transactions) {
            if (t.getDate().isAfter(startDate.minusDays(1))) {
                total += t.getAmount();
            }
        }
        return total;
    }
    
    private void printReport(String title, double total, LocalDate startDate, LocalDate endDate) {
        System.out.println(title);
        System.out.println(String.join("", Collections.nCopies(title.length(), "-")));
        System.out.println("Total: $" + total);
        
        if (startDate.equals(endDate)) {
            System.out.println("Date: " + endDate);
        } else {
            System.out.println("Period: " + startDate + " to " + endDate);
        }
    }
    
    private void saveReport(String type, double amount) {
        // Save to database
    }
}
