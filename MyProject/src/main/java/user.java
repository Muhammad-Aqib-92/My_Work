class Users {
    String email;
    String username;
    String password;
    String role;

    
    public Users(String email, String username, String password, String role) {
        this.email = email;
        this.username = username;
        this.password = password;
        this.role = role;
    }

    void showUser() {
        System.out.println(toString());
    }

    
    @Override
    public String toString() {
        return "Email: " + email + ", Username: " + username + ", Password: " + password + ", Role: " + role;
    }
}
