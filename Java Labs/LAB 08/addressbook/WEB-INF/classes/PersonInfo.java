import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import java.sql.*;

public class PersonInfo extends HttpServlet {

    public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        
        PrintWriter out = response.getWriter();

        out.println("<html><head><title>Address Book</title></head><body>");
        out.println("<h1>Address Book Records</h1>");

        try {
            Class.forName("com.mysql.jdbc.Driver");
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/address_book", "root", "root");
            Statement st = con.createStatement();
            String query = "SELECT * FROM person"; // Corrected table name
            ResultSet rs = st.executeQuery(query);

            out.println("<table border='1'><tr><th>Name</th><th>Address</th><th>Phone</th></tr>");
            while (rs.next()) {
                out.println("<tr><td>" + rs.getString("username") + "</td><td>" + rs.getString("address") + "</td><td>" + rs.getString("phone") + "</td></tr>");
            }
            out.println("</table>");

            st.close();
            con.close();
        } catch (Exception e) {
            out.println("<h2>Error: " + e.getMessage() + "</h2>");
        }

        out.println("</body></html>");
    }

    
    public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        
        PrintWriter out = response.getWriter();

        String action = request.getParameter("action").trim();
        String name = request.getParameter("name");
        String address = request.getParameter("address");
        String phone = request.getParameter("phone");

        System.out.println(action);

        try {
            Class.forName("com.mysql.jdbc.Driver");
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/address_book", "root", "root");
            Statement st = con.createStatement();
            String query = "";

            if (action == null || action.trim().isEmpty()) {
                out.println("<h2>Error: Action parameter is missing!</h2>");
            } else{
            if ("create".equalsIgnoreCase(action)) {
                query = "INSERT INTO person(username, address, phone) VALUES('" + name + "', '" + address + "', '" + phone + "')";
                st.executeUpdate(query);
                out.println("<h2>Record added successfully!</h2>");
            } else if ("update".equalsIgnoreCase(action)) {
                query = "UPDATE person SET address='" + address + "', phone='" + phone + "' WHERE username='" + name + "'"; // Corrected table name
                st.executeUpdate(query);
                out.println("<h2>Record updated successfully!</h2>");
            } else if ("delete".equalsIgnoreCase(action)) {
                query = "DELETE FROM person WHERE username='" + name + "'"; // Corrected table name
                st.executeUpdate(query);
                out.println("<h2>Record deleted successfully!</h2>");
            } else {
                out.println("<h2>Invalid action!</h2>");
            }
        }

            st.close();
            con.close();
        } catch (Exception e) {
            out.println("<h2>Error: " + e.getMessage() + "</h2>");
        }
    }
}
