import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

@WebServlet("/processServlet")
public class processServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String studentId = request.getParameter("loginid");
        String msg = "-0.0"; // Default error message
        String url;

        try {
            // Load MySQL JDBC Driver
            Class.forName("com.mysql.cj.jdbc.Driver");

            // Establish database connection
            Connection connection = DriverManager.getConnection(
                "jdbc:mysql://localhost:3306/university", // Database URL
                "root",                                   // Username
                "root"                                // Password
            );

            // Debug: Print connection success
            System.out.println("Database connected successfully.");

            // Prepare SQL query
            String query = "SELECT cgpa FROM studentinfo WHERE loginid = ?";
            PreparedStatement statement = connection.prepareStatement(query);
            statement.setString(1, studentId);

            // Debug: Print the SQL query and parameters
            System.out.println("Executing query: " + statement);

            // Execute the query
            ResultSet resultSet = statement.executeQuery();

            // Debug: Check if the result set contains rows
            if (resultSet.next()) {
                msg = resultSet.getString("cgpa"); // Retrieve CGPA
                System.out.println("CGPA found: " + msg); // Debug: Print retrieved CGPA
                url = "showServlet";
            } else {
                System.out.println("No record found for Student ID: " + studentId);
                url = "errorServlet";
            }

            // Close connection
            connection.close();
        } catch (Exception e) {
            e.printStackTrace(); // Debug: Print exception stack trace
            url = "errorServlet";
        }

        // Debug: Print the target URL
        System.out.println("Forwarding to: " + url);

        // Pass attributes to the next servlet
        request.setAttribute("loginid", studentId);
        request.setAttribute("msg", msg);

        // Forward request to the appropriate servlet
        RequestDispatcher dispatcher = request.getRequestDispatcher(url);
        dispatcher.forward(request, response);
    }
}
