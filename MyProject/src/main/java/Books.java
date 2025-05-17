class Books {
    String author;
    String title;
    String category;
    String user;

   
    public Books(String aut, String tit, String cat, String us) {
        author = aut;
        title = tit;
        category = cat;
        user = us;
    }

   
    void showBook() {
        System.out.println(toString());
    }

 
    @Override
    public String toString() {
        return "Author: " + author + ", Title: " + title + ", Category: " + category + ", User: " + user;
    }
}
