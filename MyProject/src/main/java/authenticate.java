import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet("/authenticate")
public class authenticate extends HttpServlet {
   

    
	private static final long serialVersionUID = 1L;

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        PrintWriter out = response.getWriter();
        String email = request.getParameter("email");
        String password = request.getParameter("pw");
        String role = request.getParameter("role");


        BookDao dao = new BookDao();
        Users user = dao.authenticateUser(email, password, role);

        try {
            if (user != null) {
                HttpSession session = request.getSession(true);
                session.setAttribute("role", user.role);
                session.setAttribute("userName", user.username); 
                session.setMaxInactiveInterval(600); 


                if ("admin".equals(user.role)) {
                 response.sendRedirect("adminpanel.html");
                } else if ("user".equals(user.role)) {
                 response.sendRedirect("userpanel.html");
                }
            } else {
             
            	out.println("<html>");
            	out.println("<head>");
            	out.println("<title>Incorrect</title>");
            	out.println("<link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\">");
            	out.println("<script>");
            	out.println("function redirect() {");
            	out.println("window.location.href = 'signin.html';");
            	out.println("}");
            	out.println("</script>");
            	out.println("</head>");
            	out.println("<body>");
            	out.println("<h4>Incorrect username & password</h4>");
            	out.println("<br><br>");
            	out.println("<input type='button' onclick='redirect()' value='Try Again'>");
            	out.println("</body>");
            	out.println("</html>");

            }
        } catch (Exception e) {
            out.println("Error: " + e.getMessage());
        } finally {
            
            dao.close();
            out.close();
        }
    }

    public authenticate() {
        super();
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.getWriter().append("Served at: ").append(request.getContextPath());
    }
}
