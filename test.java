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
