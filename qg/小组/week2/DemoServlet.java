package pojo;

import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;
import java.io.IOException;
@WebServlet("/demo")
public class DemoServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        handleRequest(req, resp, "GET");
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        handleRequest(req, resp, "POST");
    }

    @Override
    protected void doPut(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        handleRequest(req, resp, "PUT");
    }

    @Override
    protected void doDelete(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        handleRequest(req, resp, "DELETE");
    }

    @Override
    protected void doHead(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        handleRequest(req, resp, "HEAD");
    }

    @Override
    protected void doOptions(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        handleRequest(req, resp, "OPTIONS");
    }

    @Override
    protected void doTrace(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        handleRequest(req, resp, "TRACE");
    }


    private void handleRequest(HttpServletRequest req, HttpServletResponse resp, String method) throws IOException {
        // 根据请求类型返回不同的状态码
        switch (method) {
            case "GET":
                resp.setStatus(HttpServletResponse.SC_OK);
                resp.getWriter().println("GET request handled with status 200 OK");
                break;
            case "POST":
                resp.setStatus(HttpServletResponse.SC_CREATED);
                resp.getWriter().println("POST request handled with status 201 Created");
                break;
            case "PUT":
                resp.setStatus(HttpServletResponse.SC_NO_CONTENT);
                resp.getWriter().println("PUT request handled with status 204 No Content");
                break;
            case "DELETE":
                resp.setStatus(HttpServletResponse.SC_ACCEPTED);
                resp.getWriter().println("DELETE request handled with status 202 Accepted");
                break;
            case "HEAD":
                resp.setStatus(HttpServletResponse.SC_OK);
                // 对于HEAD请求，不返回响应体
                break;
            case "OPTIONS":
                resp.setStatus(HttpServletResponse.SC_OK);
                resp.setHeader("Allow", "GET, POST, PUT, DELETE, HEAD, OPTIONS, TRACE");
                resp.getWriter().println("OPTIONS request handled with status 200 OK");
                break;
            case "TRACE":
                resp.setStatus(HttpServletResponse.SC_OK);
                resp.getWriter().println("TRACE request handled with status 200 OK");
                break;
            default:
                resp.setStatus(HttpServletResponse.SC_METHOD_NOT_ALLOWED);
                resp.getWriter().println("Method " + method + " is not allowed");
        }
    }
}

