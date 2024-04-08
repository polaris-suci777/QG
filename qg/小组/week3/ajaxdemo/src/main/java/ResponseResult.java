import com.fasterxml.jackson.annotation.JsonInclude;
import com.fasterxml.jackson.databind.annotation.JsonSerialize;
import com.fasterxml.jackson.databind.ser.std.ToStringSerializer;

@JsonInclude(JsonInclude.Include.NON_NULL)
public class ResponseResult {
    @JsonSerialize(using = ToStringSerializer.class)
    private Long code;
    private String message;
    private Object data;

    public ResponseResult(Long code, String message, Object data) {
        this.code = code;
        this.message = message;
        this.data = data;
    }

    // Getter and Setter methods  
    public Long getCode() {
        return code;
    }

    public void setCode(Long code) {
        this.code = code;
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }

    public Object getData() {
        return data;
    }

    public void setData(Object data) {
        this.data = data;
    }
}