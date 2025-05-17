import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpServletRequest;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet("/errorServlet")
public class errorServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String studentId = (String) request.getAttribute("loginid");
        String msg = (String) request.getAttribute("msg");

        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        out.println("<h1>Error</h1>");
        out.println("<p>Student ID: " + studentId + "</p>");
        out.println("<p>Message: " + msg + " (No CGPA found)</p>");
    }
}
