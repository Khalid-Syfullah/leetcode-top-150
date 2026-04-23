import com.anthropic.client.AnthropicClient;
import com.anthropic.client.okhttp.AnthropicOkHttpClient;
import com.anthropic.core.http.StreamResponse;
import com.anthropic.models.messages.*;

import java.util.Scanner;

public class CodeQA {
    public static void main(String[] args) throws Exception {
        AnthropicClient client = AnthropicOkHttpClient.fromEnv();
        Scanner scanner = new Scanner(System.in);

        System.out.println("Paste your code (blank line to finish):");
        StringBuilder code = new StringBuilder();
        while (scanner.hasNextLine()) {
            String line = scanner.nextLine();
            if (line.isEmpty()) break;
            code.append(line).append("\n");
        }

        System.out.print("Your question: ");
        String question = scanner.nextLine();

        String prompt = "Here is the code:\n\n```java\n" + code + "```\n\n" + question;

        System.out.println("\n--- Answer ---");

        MessageCreateParams params = MessageCreateParams.builder()
                .model("claude-opus-4-7")
                .maxTokens(8192L)
                .thinking(ThinkingConfigAdaptive.builder().build())
                .addUserMessage(prompt)
                .build();

        try (StreamResponse<RawMessageStreamEvent> stream = client.messages().createStreaming(params)) {
            stream.stream()
                    .flatMap(event -> event.contentBlockDelta().stream())
                    .flatMap(delta -> delta.delta().text().stream())
                    .forEach(text -> {
                        System.out.print(text.text());
                        System.out.flush();
                    });
        }

        System.out.println();
    }
}
